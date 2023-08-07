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
    ServerModel(std::weak_ptr<boost::asio::io_context> io_context);
    virtual ~ServerModel(void) = default;

    // Getters starts;

    std::weak_ptr<boost::asio::io_context> io_context(void) override;
    std::weak_ptr<boost::asio::ip::tcp::acceptor> acceptor(void) override;

    // Getters ends;

    // Setters starts;

    
    
    // Setters ends;

private:
    // Private Setters starts;
    
    bool set_io_context(std::weak_ptr<boost::asio::io_context> val);

    // Private Setters ends;

    // Private Update methods starts;

    bool update_acceptor(void);

    // Private Update methods ends;

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