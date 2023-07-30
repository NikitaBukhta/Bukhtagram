#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_ICLIENTCONTROLLER_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_ICLIENTCONTROLLER_HPP

#include <memory>

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

class IClientController {
public:
    virtual void connect_to(const std::string &address, uint16_t port) = 0;
};

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_ICLIENTCONTROLLER_HPP;