#include "ClientController.hpp"

#include <boost/log/trivial.hpp>
#include <boost/core/demangle.hpp>
#include <boost/current_function.hpp>

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

ClientController::ClientController(std::weak_ptr<models::IClientModel> client_model)
    : m_client_model(client_model.lock())
{

}

ClientController::~ClientController(void) {
    auto socket = m_client_model->socket().lock();
    socket->close();
}

void ClientController::connect_to(const std::string &address, uint16_t port) {
    boost::system::error_code error_code;
    auto socket = m_client_model->socket().lock();
    boost::asio::ip::tcp::endpoint server_endpoint(
        boost::asio::ip::address::from_string(address), port
    );
    socket->connect(server_endpoint, error_code);
    handle_error(error_code);
}

bool ClientController::handle_error(boost::system::error_code &error) {
    std::cout << "Called handle_error with error #" << error.value() << std::endl;
    if (error.value() == boost::system::errc::success) {
        return false;
    }

    BOOST_LOG_TRIVIAL(info) << error.what();

    return true;
}

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;