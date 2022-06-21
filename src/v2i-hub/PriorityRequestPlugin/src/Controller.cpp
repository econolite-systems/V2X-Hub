#include "Controller.h"
#include "Ntcip1211.h"

using namespace std;

Controller::Controller()
{
}

void Controller::UpdateConfig(std::string snmpIp, uint32_t snmpPort, std::string community)
{
    lock_guard<mutex> lock(_cfgLock);
    _snmpIp = snmpIp;
    _snmpPort = snmpPort;
}

ntcip1211::prgPriorityStatusBuffer Controller::PollPriorityRequestStatus() const
{
    struct ntcip1211::prgPriorityStatusBuffer statusbuffer;
    struct snmp_session *session = BuildSnmpSession();
    if (session)
    {
        netsnmp_pdu *response = GetSNMP(PRGPRIORITYSTATUSBUFFER);
        if (response)
        {
            netsnmp_variable_list *vars = response->variables;
            if (vars->type == ASN_OCTET_STR)
            {
                memcpy(&statusbuffer, vars->val.string, min(vars->val_len, sizeof(ntcip1211::prgPriorityStatusBuffer)));
            }
            snmp_free_pdu(response);
        }
        snmp_close(session);
    }
    SOCK_CLEANUP;
    return statusbuffer;
}

bool Controller::SendPriorityRequest(const struct ntcip1211::prgPriorityRequest &request) const
{
    const int size = sizeof(ntcip1211::prgPriorityRequest);
    bool result = false;
    SOCK_STARTUP;
    struct snmp_session *session = BuildSnmpSession();
    if (session)
    {
        char *octet = new char[size];
        netsnmp_pdu *response = SetSNMPOctet(PRGPRIORITYUPDATE, octet, size);
        if (response)
        {

            if (response->errstat == SNMP_ERR_NOERROR)
            {
                result = true;
            }
            snmp_free_pdu(response);
        }
        delete octet;
        snmp_close(session);
    }
    return result;
}

struct snmp_session *Controller::BuildSnmpSession() const
{
    lock_guard<mutex> lock(const_cast<mutex &>(_cfgLock));
    struct snmp_session session_info;
    // open snmp session
    snmp_sess_init(&session_info);
    string peername = _snmpIp;
    peername.append(":");
    peername.append(to_string(_snmpPort));
    session_info.peername = (char *)peername.c_str();
    session_info.version = SNMP_VERSION_1;
    session_info.community = (u_char *)_community.c_str();
    session_info.community_len = strlen(_community.c_str());
    netsnmp_session *result = snmp_open(&session_info);
    if (!result)
    {
        // Could not open session
        snmp_sess_perror("ASC", &session_info);
        return NULL;
    }
    return result;
}

netsnmp_pdu *Controller::SendSNMP(netsnmp_pdu *pdu) const
{
    SOCK_STARTUP;
    netsnmp_session *ss = BuildSnmpSession();
    netsnmp_pdu *response = NULL;

    if (ss)
    {
        int status = snmp_synch_response(ss, pdu, &response);
        if (!response)
        {
            SOCK_CLEANUP;
            return response;
        }
        if (status != STAT_SUCCESS && response->errstat != SNMP_ERR_NOERROR)
        {
            printf("SignalControllerNTCIP::SendSNMP Status not successful\n");
            if (status == STAT_SUCCESS)
            {
                fprintf(stderr, "Error in packet\nReason: %s\n", snmp_errstring(response->errstat));
            }
            else if (status == STAT_TIMEOUT)
            {
                fprintf(stderr, "Timeout: No response");
            }
            else
            {
                fprintf(stderr, "Error");
                snmp_sess_perror("SendSNMP", ss);
            }
            SOCK_CLEANUP;
            return NULL;
        }

        snmp_close(ss);
    }
    SOCK_CLEANUP;
    return response;
}

netsnmp_pdu *Controller::GetSNMP(const char *requestOID) const
{
    netsnmp_pdu *pdu;
    netsnmp_pdu *response = NULL;

    oid anOID[MAX_OID_LEN];
    size_t anOID_len;

    pdu = snmp_pdu_create(SNMP_MSG_GET);

    anOID_len = MAX_OID_LEN;

    if (!snmp_parse_oid(requestOID, anOID, &anOID_len))
    {
        snmp_perror(requestOID);
        SOCK_CLEANUP;
        return NULL;
    }
    snmp_add_null_var(pdu, anOID, anOID_len);

    response = SendSNMP(pdu);
    return response;
}

netsnmp_pdu *Controller::SetSNMPOctet(const char *requestOID, const char *value, const size_t length) const
{
    netsnmp_pdu *pdu;
    netsnmp_pdu *response = NULL;

    oid anOID[MAX_OID_LEN];
    size_t anOID_len;

    pdu = snmp_pdu_create(SNMP_MSG_SET);

    anOID_len = MAX_OID_LEN;

    if (!snmp_parse_oid(requestOID, anOID, &anOID_len))
    {
        snmp_perror(requestOID);
        SOCK_CLEANUP;
        return NULL;
    }
    snmp_pdu_add_variable(pdu, anOID, anOID_len, 'x', value, length);

    response = SendSNMP(pdu);
    return response;
}