/**********************************************************************************************************************
 * Bukhtagram                                                                                                         *
 *                                                                                                                    *
 * Author: Bukhta Mykyta                                                                                              *
 *                                                                                                                    *
 * Copyright ©2023 Bukhta Mykyta                                                                                      *
 *                                                                                                                    *
 * This software is distributed under the following license:                                                          *
 *                                                                                                                    *
 * 1. This code may not be modified, redistributed, or used to create derivative works.                               *
 * 2. Any use of this code for commercial purposes is prohibited without prior written permission of the author.      *
 * 3. The author is not liable for any damages caused by the use of this software.                                    *
 * 4. Copies of this license or references to it must be included in all copies or significant parts of the software. *
 *                                                                                                                    *
 * For permission for commercial use, contact the author at the following address: nikita.bukhta.dev@gmail.com.       *
 **********************************************************************************************************************                                                                                                                    *
 */

#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP

#include "IClientController.hpp"
#include "IClientModel.hpp"

#include <boost/system/error_code.hpp>

#include <memory>
#include <string>

#include <inttypes.h>

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

class ClientController : public IClientController {
public:
    ClientController(std::weak_ptr<models::IClientModel> client_model);
    virtual ~ClientController(void);

    // IClientController overriding starts;

    void connect_to(const std::string &address, uint16_t port) override;

    // IClientController overriding ends;

private:
    bool handle_error(const boost::system::error_code &error);

private:
    std::shared_ptr<models::IClientModel> m_client_model;
};

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_CONTROLLERS_CLIENTCONTROLLER_HPP;