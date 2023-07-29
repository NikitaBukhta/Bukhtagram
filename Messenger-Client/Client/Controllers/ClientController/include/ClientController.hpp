#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP

#include "IClientModel.hpp"

#include <memory>

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

class ClientController {
public:
    ClientController(std::weak_ptr<models::IClientModel> client_model);
    virtual ~ClientController(void) = default;

private:
    std::shared_ptr<models::IClientModel> m_client_model;
};

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP;