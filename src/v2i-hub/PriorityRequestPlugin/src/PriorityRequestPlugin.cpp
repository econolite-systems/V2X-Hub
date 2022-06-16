//==========================================================================
// Name        : PriorityRequestPlugin.cpp
// Author      : Econolite Systems
// Version     :
// Copyright   : Copyright (c) 2022 Econolite. All rights reserved.
// Description : Priority Request Plugin
//==========================================================================

#include "PluginClient.h"
#include "PluginDataMonitor.h"

#include <atomic>
#include <thread>
#include <DecodedBsmMessage.h>
#include <tmx/j2735_messages/MapDataMessage.hpp>
#include "Controller.h"

using namespace std;
using namespace tmx;
using namespace tmx::utils;
using namespace tmx::messages;

/**
 * This plugin processes priority requests sends them to the signal and monitors that status and reports that status to the TMC/cloud.
 */
class PriorityRequestPlugin: public PluginClient
{
public:
	PriorityRequestPlugin(std::string);
	virtual ~PriorityRequestPlugin();
	int Main();
protected:
	void UpdateConfigSettings();

	// Virtual method overrides.
	void OnConfigChanged(const char *key, const char *value);
	void OnStateChange(IvpPluginState state);

	void HandleDataChangeMessage(DataChangeMessage &msg, routeable_message &routeableMsg);
private:
	std::atomic<uint64_t> _frequency{0};
	DATA_MONITOR(_frequency);   // Declares the monitoring of _frequency
	Controller _controller;
};

/**
 * Construct a new PriorityRequestPlugin with the given name.
 *
 * @param name The name to give the plugin for identification purposes.
 */
PriorityRequestPlugin::PriorityRequestPlugin(string name): PluginClient(name), _controller()
{
	// The log level can be changed from the default here.
	FILELog::ReportingLevel() = FILELog::FromString("DEBUG");

	// This is an internal message type that is used to track some plugin data that changes
	AddMessageFilter<DataChangeMessage>(this, &PriorityRequestPlugin::HandleDataChangeMessage);

	// Subscribe to all messages specified by the filters above.
	SubscribeToMessages();
}

PriorityRequestPlugin::~PriorityRequestPlugin()
{
}

void PriorityRequestPlugin::UpdateConfigSettings()
{
	// Configuration settings are retrieved from the API using the GetConfigValue template class.
	// This method does NOT execute in the main thread, so variables must be protected
	// (e.g. using std::atomic, std::mutex, etc.).

	int instance;
	GetConfigValue("Instance", instance);

	GetConfigValue("Frequency", __frequency_mon.get());
	__frequency_mon.check();
}


void PriorityRequestPlugin::OnConfigChanged(const char *key, const char *value)
{
	PluginClient::OnConfigChanged(key, value);

	// Just update everything
	UpdateConfigSettings();
}

void PriorityRequestPlugin::OnStateChange(IvpPluginState state)
{
	PluginClient::OnStateChange(state);

	if (state == IvpPluginState_registered)
	{
		UpdateConfigSettings();
		SetStatus("Registered", 0);
	}
}

// Example of handling
void PriorityRequestPlugin::HandleDataChangeMessage(DataChangeMessage &msg, routeable_message &routeableMsg)
{
	PLOG(logINFO) << "Received a data change message: " << msg;

	PLOG(logINFO) << "Data field " << msg.get_untyped(msg.Name, "?") <<
			" has changed from " << msg.get_untyped(msg.OldValue, "?") <<
			" to " << msg.get_untyped(msg.NewValue, to_string(_frequency));
}

// Override of main method of the plugin that should not return until the plugin exits.
int PriorityRequestPlugin::Main()
{
	PLOG(logINFO) << "Starting plugin.";

	while (_plugin->state != IvpPluginState_error)
	{
		ntcip1211::prgPriorityStatusBuffer status = _controller.PollPriorityRequestStatus();
		// send the status to someone
		PLOG(logDEBUG) << """Main thread sleeping" << endl;

		this_thread::sleep_for(chrono::milliseconds(_frequency > 0 ? static_cast<int>(_frequency) : 100));
	}

	PLOG(logINFO) << "Plugin terminating gracefully.";
	return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
	return run_plugin<PriorityRequestPlugin>("PriorityRequestPlugin", argc, argv);
}
