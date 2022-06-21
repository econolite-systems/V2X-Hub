#ifndef _PRIORITY_REQUEST_MESSAGE_H_
#define _PRIORITY_REQUEST_MESSAGE_H_

#include <tmx/messages/routeable_message.hpp>
#include <string>
namespace PriorityRequest
{

    class PriorityRequestMessage : public tmx::message
    {
    public:
        static constexpr const char *MessageType = "PRIORITY_REQUEST";
        static constexpr const char *MessageSubType = "REQUEST";

        std_attribute(this->msg, uint8_t, RequestID, 0,)
        std_attribute(this->msg, std::string, VehicleID, "", )
        std_attribute(this->msg, uint8_t, VehicleClassType, 0, )
        std_attribute(this->msg, uint8_t, VehicleClassLevel, 0, )
        std_attribute(this->msg, uint8_t, StrategyNumber, 0, )
        std_attribute(this->msg, uint16_t, TimeOfServiceDesired, 0, )
        std_attribute(this->msg, uint16_t, TimeOfEstimatedDeparture, 0, )
    }; 
};
#endif // _PRIORITY_REQUEST_MESSAGE_H_