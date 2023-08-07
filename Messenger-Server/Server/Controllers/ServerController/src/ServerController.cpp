#include "ServerController.hpp"

#include <boost/asio/placeholders.hpp>
#include <boost/bind/bind.hpp>
#include <boost/system/error_code.hpp>

#include <exception>

namespace bukhtagram {
namespace ms {
namespace server {
namespace controllers {

ServerController::ServerController(std::weak_ptr<models::IServerModel> server_model)
    : m_server_model(server_model.lock())
{
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";
}

ServerController::~ServerController(void) {
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";

    auto acceptor = m_server_model->acceptor().lock();
    acceptor->close();
}

void ServerController::run(const std::string &server_address, uint16_t server_port) {
    DECLARE_TAG_SCOPE
    LOG_INFO << "called";

    boost::system::error_code error;
    boost::asio::ip::tcp::endpoint server_endpoint(boost::asio::ip::address::from_string(server_address), server_port);
    auto acceptor = m_server_model->acceptor().lock();

    // Bind the acceptor to the server endpoint and start the acceptor listening;
    acceptor->open(server_endpoint.protocol(), error);
    handle_error(error);
    acceptor->bind(server_endpoint, error);
    handle_error(error);
    acceptor->listen();

    accept_connection();
}

void ServerController::accept_connection(void) {
    DECLARE_TAG_SCOPE
    LOG_INFO << "called";

    // boost::system::error_code error;
    auto acceptor = m_server_model->acceptor().lock();
    auto client_socket = std::make_shared<boost::asio::ip::tcp::socket>(*m_server_model->io_context().lock());
    // TODO: find an idea how to use this method without try... catch block in main function);
    acceptor->async_accept(*client_socket, boost::bind(
            &ServerController::handle_accept, this, client_socket, boost::asio::placeholders::error
        )
    );
}

void ServerController::handle_accept(std::weak_ptr<boost::asio::ip::tcp::socket> weak_client_socket, const boost::system::error_code &error) {
    DECLARE_TAG_SCOPE
    LOG_INFO << "called";

    handle_error(error);
    
    //auto client_socket = weak_client_socket.lock();
    accept_connection();
}

bool ServerController::handle_error(const boost::system::error_code &error) {
    DECLARE_TAG_SCOPE;

    if (error.value() == boost::system::errc::success) {
        LOG_TRACE << "no errors handled";
        return false;
    }

    LOG_ERROR << error.what();
    return true;
}

}   // !controllers;
}   // !server;
}   // !ms;
}   // !bukhtagram;