#ifndef BUKHTAGRAM_MESSENGERSERVER_SERVER_CONTROLLERS_ISERVERCONTROLLER_HPP
#define BUKHTAGRAM_MESSENGERSERVER_SERVER_CONTROLLERS_ISERVERCONTROLLER_HPP

#include <string>

namespace bukhtagram {
namespace ms {
namespace server {
namespace controllers {

class IServerController {
public:
    virtual void run(const std::string &server_address, uint16_t server_port) = 0;
};

}   // !controllers;
}   // !server;
}   // !ms;
}   // !bukhtagram;


#endif  // !BUKHTAGRAM_MESSENGERSERVER_SERVER_CONTROLLERS_ISERVERCONTROLLER_HPP;