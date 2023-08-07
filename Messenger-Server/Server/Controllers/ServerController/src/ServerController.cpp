#include "ServerController.hpp"

#include <boost/bind/bind.hpp>

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

    // There we should set endpont;

    // auto acceptor = m_server_model->acceptor().lock();
    // boost::asio::ip::tcp::endpoint server_endpoint(boost::asio::ip::address::from_string(server_address), server_port);
    // boost::asio::ip::tcp::endpoint server_endpoint(boost::asio::ip::tcp::v4(), server_port);

    // acceptor->open(server_endpoint.protocol());
    // acceptor->bind(server_endpoint);
    // acceptor.reset();

    // auto client_socket = std::make_shared<boost::asio::ip::tcp::socket>(*m_server_model->io_context().lock());
    // acceptor->accept(*client_socket);
    // handle_accept(client_socket);

    accept_connection();
}

void ServerController::accept_connection(void) {
    DECLARE_TAG_SCOPE
    LOG_INFO << "called";

    auto acceptor = m_server_model->acceptor().lock();
    auto client_socket = std::make_shared<boost::asio::ip::tcp::socket>(*m_server_model->io_context().lock());
    acceptor->async_accept(*client_socket, boost::bind(&ServerController::handle_accept, this, client_socket));
}

void ServerController::handle_accept(std::weak_ptr<boost::asio::ip::tcp::socket> weak_client_socket) {
    DECLARE_TAG_SCOPE
    LOG_INFO << "called";
    
    //auto client_socket = weak_client_socket.lock();
    accept_connection();
}

}   // !controllers;
}   // !server;
}   // !ms;
}   // !bukhtagram;