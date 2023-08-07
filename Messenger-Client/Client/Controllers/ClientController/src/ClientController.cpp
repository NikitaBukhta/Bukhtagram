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

#include "ClientController.hpp"

#include "Logger.hpp"

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

ClientController::ClientController(std::weak_ptr<models::IClientModel> client_model)
    : m_client_model(client_model.lock())
{
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";
}

ClientController::~ClientController(void) {
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";

    auto socket = m_client_model->socket().lock();
    socket->close();
}

void ClientController::connect_to(const std::string &address, uint16_t port) {
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";
    boost::system::error_code error_code;
    auto socket = m_client_model->socket().lock();
    boost::asio::ip::tcp::endpoint server_endpoint(
        boost::asio::ip::address::from_string(address), port
    );
    socket->connect(server_endpoint, error_code);
    if (!handle_error(error_code)) {
        LOG_INFO << "connected!";
    }
}

bool ClientController::handle_error(const boost::system::error_code &error) {
    DECLARE_TAG_SCOPE;

    if (error.value() == boost::system::errc::success) {
        LOG_TRACE << "no errors handled";
        return false;
    }

    LOG_ERROR << error.what();
    return true;
}

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;