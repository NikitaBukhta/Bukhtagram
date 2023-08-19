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

#include "ClientHandlerController.hpp"
#include "ClientHandlerModel.hpp"

#include "Logger.hpp"

namespace bukhtagram {
namespace ms {
namespace server {
namespace controllers {

ClientHandlerController::ClientHandlerController(std::weak_ptr<models::IClientHandlerModel> client_handler_model)
    : m_client_handler_model(client_handler_model.lock())
{
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";
}

void ClientHandlerController::run(void) {
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";
}

void ClientHandlerController::add(std::weak_ptr<boost::asio::ip::tcp::socket> client_socket) {
    DECLARE_TAG_SCOPE;
    
    models::ClientConnection client_connection = {
        client_socket.lock()
    };

    if (m_client_handler_model->add(client_connection)) {
        LOG_INFO << "new client added to clients list";
    } else {
        LOG_WARNING << "Cannot to add client to clients list";
    }
}

}   // !controllers;
}   // !server;
}   // !ms;
}   // !bukhtagram;