//==========================================================================
// Name        : PRSPlugin.cpp
// Author      : Econolite Systems
// Version     :
// Copyright   : Copyright (c) 2022 Econolite. All rights reserved.
// Description : Priority Request Plugin
//==========================================================================

#include "PluginClient.h"
#include "PluginDataMonitor.h"
#include "PriorityRequestMessage.h"

#include <atomic>
#include <thread>
#include <DecodedBsmMessage.h>
#include <tmx/j2735_messages/MapDataMessage.hpp>
#include <tmx/j2735_messages/BasicSafetyMessage.hpp>
#include "Ntcip1211.h"

using namespace std;
using namespace tmx;
using namespace tmx::utils;
using namespace tmx::messages;

/**
 * This plugin processes priority requests sends them to the signal and monitors that status and reports that status to the TMC/cloud.
 */
class PRSPlugin: public PluginClient
{
public:
	PRSPlugin(std::string);
	virtual ~PRSPlugin();
	int Main();
protected:
	void UpdateConfigSettings();

	// Virtual method overrides.
	void OnConfigChanged(const char *key, const char *value);
	void OnStateChange(IvpPluginState state);

	void HandleDataChangeMessage(DataChangeMessage &msg, routeable_message &routeableMsg);
	void HandlePriorityRequest(PriorityRequest::PriorityRequestMessage &msg, routeable_message &routeableMsg);
	void HandleRealTimePublish(BsmMessage &msg, routeable_message &routeableMsg);
private:
	std::atomic<uint64_t> _frequency{0};
	DATA_MONITOR(_frequency);   // Declares the monitoring of _frequency
};

/**
 * Construct a new PRSPlugin with the given name.
 *
 * @param name The name to give the plugin for identification purposes.
 */
PRSPlugin::PRSPlugin(string name): PluginClient(name)
{
	// The log level can be changed from the default here.
	FILELog::ReportingLevel() = FILELog::FromString("DEBUG");

	AddMessageFilter <BsmMessage> (this, &PRSPlugin::HandleRealTimePublish);

	// This is an internal message type that is used to track some plugin data that changes
	AddMessageFilter<DataChangeMessage>(this, &PRSPlugin::HandleDataChangeMessage);

	// Subscribe to all messages specified by the filters above.
	SubscribeToMessages();
}

PRSPlugin::~PRSPlugin()
{
}

void PRSPlugin::UpdateConfigSettings()
{
	// Configuration settings are retrieved from the API using the GetConfigValue template class.
	// This method does NOT execute in the main thread, so variables must be protected
	// (e.g. using std::atomic, std::mutex, etc.).

	int instance;
	GetConfigValue("Instance", instance);

	GetConfigValue("Frequency", __frequency_mon.get());
	__frequency_mon.check();
}


void PRSPlugin::OnConfigChanged(const char *key, const char *value)
{
	PluginClient::OnConfigChanged(key, value);

	// Just update everything
	UpdateConfigSettings();
}

void PRSPlugin::OnStateChange(IvpPluginState state)
{
	PluginClient::OnStateChange(state);

	if (state == IvpPluginState_registered)
	{
		UpdateConfigSettings();
		SetStatus("Registered", 0);
	}
}


template <class Precision>
string getISOCurrentTimestamp()
{
	auto now = chrono::system_clock::now();
	return date::format("%FT%TZ", date::floor<Precision>(now));
}

/**
 * Method that's called to process a message that this plugin has
 * subscribed for.  This particular method decodes the BSM message and
 * logs selective fields to a log file.
 *
 * @param msg BSMMessage that is received
 * @routeable_message not used
 */
void PRSPlugin::HandleRealTimePublish(BsmMessage &msg, routeable_message &routeableMsg)
{
	auto bsm=msg.get_j2735_data();

	char *teststring=new char[10000];

	std::sprintf(teststring, "{\"BsmMessageContent\":[{\"metadata\":{\"utctimestamp\":\"%s\"},\"payload\":\"%s\"}]}", getISOCurrentTimestamp<chrono::microseconds>().c_str(), routeableMsg.get_payload_str().c_str());

	//  check for schedule
	// if(_freqCounter++%_scheduleFrequency == 0)
	// 		QueueKafkaMessage(kafka_producer, _BSMkafkaTopic, teststring);
}
// Handle priority request messages
void PRSPlugin::HandlePriorityRequest(PriorityRequest::PriorityRequestMessage &msg, routeable_message &routeableMsg)
{
	ntcip1211::prgPriorityRequest request;
	request.requestID = msg.get_RequestID();
	std::string vehicleid = msg.get_VehicleID();
	vehicleid.resize(17);
	memcpy(request.vehicleID, vehicleid.c_str(), 17);
	request.vehicleClassType = msg.get_RequestID();
	request.vehicleClassLevel = msg.get_VehicleClassLevel();
	request.StrategyNumber = msg.get_StrategyNumber();
	request.TimeOfServiceDesired = msg.get_TimeOfServiceDesired();
	request.TimeOfEstimatedDeparture = msg.get_TimeOfEstimatedDeparture();
}

// Handle data changed message
void PRSPlugin::HandleDataChangeMessage(DataChangeMessage &msg, routeable_message &routeableMsg)
{
	PLOG(logINFO) << "Received a data change message: " << msg;

	PLOG(logINFO) << "Data field " << msg.get_untyped(msg.Name, "?") <<
			" has changed from " << msg.get_untyped(msg.OldValue, "?") <<
			" to " << msg.get_untyped(msg.NewValue, to_string(_frequency));
}

// Override of main method of the plugin that should not return until the plugin exits.
int PRSPlugin::Main()
{
	PLOG(logINFO) << "Starting plugin.";

	while (_plugin->state != IvpPluginState_error)
	{
		// send the status to someone
		PLOG(logDEBUG) << """Main thread sleeping" << endl;

		this_thread::sleep_for(chrono::milliseconds(_frequency > 0 ? static_cast<int>(_frequency) : 100));
	}

	PLOG(logINFO) << "Plugin terminating gracefully.";
	return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
	return run_plugin<PRSPlugin>("PRSPlugin", argc, argv);
}
