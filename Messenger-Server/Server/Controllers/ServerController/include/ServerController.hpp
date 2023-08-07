#ifndef BUKHTAGRAM_MESSENGERSERVER_SERVER_CONTROLLERS_SERVERCONTROLLER_HPP
#define BUKHTAGRAM_MESSENGERSERVER_SERVER_CONTROLLERS_SERVERCONTROLLER_HPP

#include "IServerController.hpp"
#include "IServerModel.hpp"

#include "Logger.hpp"

#include <memory>

namespace bukhtagram {
namespace ms {
namespace server {
namespace controllers {

class ServerController : public IServerController{
public:
    ServerController(std::weak_ptr<models::IServerModel> server_model);
    virtual ~ServerController(void);

    // Overriding starts;

    void run(const std::string &server_address, uint16_t server_port) override;

    // Overriding ends;

private:
    void accept_connection(void);

    void handle_accept(std::weak_ptr<boost::asio::ip::tcp::socket> weak_client_socket, const boost::system::error_code &error);
    bool handle_error(const boost::system::error_code &error);

private:
    std::shared_ptr<models::IServerModel> m_server_model;
};

}   // !controllers;
}   // !server;
}   // !ms;
}   // !bukhtagram;


#endif  // !BUKHTAGRAM_MESSENGERSERVER_SERVER_CONTROLLERS_SERVERCONTROLLER_HPP;