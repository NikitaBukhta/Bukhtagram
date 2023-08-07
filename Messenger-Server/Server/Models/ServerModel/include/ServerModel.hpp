#ifndef BUKHTAGRAM_MESSENGERSERVER_SERVER_MODELS_SERVERMODELS_HPP
#define BUKHTAGRAM_MESSENGERSERVER_SERVER_MODELS_SERVERMODELS_HPP

#include "IServerModel.hpp"

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <memory>
#include <mutex>

namespace bukhtagram {
namespace ms {
namespace server {
namespace models {

class ServerModel : public IServerModel {
public:
    ServerModel(std::weak_ptr<boost::asio::io_context> val);
    virtual ~ServerModel(void) = default;

    // Getters starts;

    std::weak_ptr<boost::asio::io_context> io_context(void) override;
    std::weak_ptr<boost::asio::ip::tcp::acceptor> acceptor(void) override;

    // Getters ends;

    // Setters starts;

    bool set_io_contex(std::weak_ptr<boost::asio::io_context> val) override;
    
    // Setters ends;

    // Update methods starts;

    bool update_acceptor(void) override;
    bool update_acceptor(uint16_t port) override;

    // Update methods ends;

private:
    std::mutex m_io_context_mutex;
    std::shared_ptr<boost::asio::io_context> m_io_context;

    std::mutex m_accpetor_mutex;
    std::shared_ptr<boost::asio::ip::tcp::acceptor> m_acceptor;
    
};

}   // !models;
}   // !server;
}   // !ms;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERSERVER_SERVER_MODELS_SERVERMODELS_HPP;