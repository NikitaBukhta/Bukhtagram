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

bool ClientController::handle_error(boost::system::error_code &error) {
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