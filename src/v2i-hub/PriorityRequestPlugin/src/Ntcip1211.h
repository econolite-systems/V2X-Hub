#ifndef _NTCIP_1211_H_
#define _NTCIP_1211_H_
#include <bits/stdint-uintn.h>

namespace ntcip1211
{
    #define PRGPRIORITYSTATUSCONTROL "1.3.6.1.4.1.1206.4.2.11.2.3.0"
    struct prgPriorityStatusControl
    {
        uint8_t requestID;
        char vehicleID[17];
        uint8_t vehicleClassType;
        uint8_t vehicleClassLevel;
        uint8_t StrategyNumber;
    }__attribute__((packed));
    static_assert(sizeof(prgPriorityStatusControl) == 21);

    enum priorityRequestStatus : uint8_t
    {
            idleNotValid = 1,// (1),
            readyQueued = 2, // (2),
            readyOverridden = 3, // (3),
            activeProcessing = 4, // (4),
            activeCancel = 5, // (5),
            activeOverride = 6, // (6),
            activeNotOverridden = 7, // (7),
            closedCanceled = 8, // (8),
            reserviceError = 9, // (9),
            closedTimeToLiveError =10, // (10),
            closedTimerError = 11, // (11),
            closedStrategyError = 12, // (12),
            closedCompleted = 13, // (13),
            activeAdjustNotNeeded = 14, //(14),
            closedFlash = 15, // (15)
    };
    #define PRGPRIORITYSTATUSBUFFER "1.3.6.1.4.1.1206.4.2.11.2.4.0"
    struct prgPriorityStatusBuffer
    {
        uint8_t requestID;
        char vehicleID[17];
        uint8_t vehicleClassType;
        uint8_t vehicleClassLevel;
        uint8_t StrategyNumber;
        priorityRequestStatus StatusInPRS;
        uint8_t pad;
    }__attribute__((packed));
    static_assert(sizeof(prgPriorityStatusBuffer) == 23);

    #define PRGPRIORITYREQUEST "1.3.6.1.4.1.1206.4.2.11.2.1.0"
    #define PRGPRIORITYUPDATE "1.3.6.1.4.1.1206.4.2.11.2.2.0"
    struct prgPriorityRequest
    {
        uint8_t requestID;
        char vehicleID[17];
        uint8_t vehicleClassType;
        uint8_t vehicleClassLevel;
        uint8_t StrategyNumber;
        uint16_t TimeOfServiceDesired;
        uint16_t TimeOfEstimatedDeparture;
    }__attribute__((packed));
    static_assert(sizeof(prgPriorityRequest) == 25);
};
#endif // _NTCIP_1211_H_