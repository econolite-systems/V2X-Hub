#ifndef _PRIORITYREQUESTCONTROLLER_H_
#define _PRIORITYREQUESTCONTROLLER_H_

#include <string>
#include <mutex>

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include "Ntcip1211.h"

class Controller
{
    private:
    // private unimplemented copy and assignment operator
    Controller(const Controller & copy);
    Controller &operator=(const Controller &assignee);

    // The following should only be access while owning the _cfgLock
	std::mutex _cfgLock;
    std::string _snmpIp;
    uint32_t _snmpPort;
    std::string _community;

    struct snmp_session* BuildSnmpSession() const;

	netsnmp_pdu* SendSNMP(netsnmp_pdu *pdu) const;
	netsnmp_pdu* GetSNMP(const char* requestOID) const;
	netsnmp_pdu* SetSNMPOctet(const char* requestOID, const char *value, const size_t length) const;

public:
    Controller();

    void UpdateConfig(std::string snmpIp, uint32_t snmpPort, std::string community);

    ntcip1211::prgPriorityStatusBuffer PollPriorityRequestStatus() const;

    bool SendPriorityRequestStatus(const struct ntcip1211::prgPriorityRequest &request) const;
};

#endif // _PRIORITYREQUESTCONTROLLER_H_
