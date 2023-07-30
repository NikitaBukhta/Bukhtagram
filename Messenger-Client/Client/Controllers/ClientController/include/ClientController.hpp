#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP

#include "IClientController.hpp"
#include "IClientModel.hpp"

#include <boost/system/error_code.hpp>

#include <memory>
#include <string>
#include <iostream>

#include <inttypes.h>

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

class ClientController : public IClientController {
public:
    ClientController(std::weak_ptr<models::IClientModel> client_model);
    virtual ~ClientController(void);

    void connect_to(const std::string &address, uint16_t port);

private:
    bool handle_error(boost::system::error_code &error);

private:
    std::shared_ptr<models::IClientModel> m_client_model;
};

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP;