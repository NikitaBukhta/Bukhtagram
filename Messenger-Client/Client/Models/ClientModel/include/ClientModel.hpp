#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_CLIENTMODEL_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_CLIENTMODEL_HPP

#include "IClientModel.hpp"

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <mutex>
#include <memory>

namespace bukhtagram {
namespace mc {
namespace client {
namespace models {

class ClientModel : public IClientModel {
public:
    ClientModel(void) = default;
    virtual ~ClientModel(void) = default;

    // Getters starts;

    std::weak_ptr<boost::asio::io_context> io_context(void) const override;
    std::weak_ptr<boost::asio::ip::tcp::socket> socket(void) const override;

    // Getters ends;

    // Setters starts;

    bool set_io_context(std::weak_ptr<boost::asio::io_context> val) override;

    // Setters ends;

    // Other methods starts;

    bool update_socket(void) override;

    // Other methods ends;

private:
    mutable std::mutex m_io_context_mutex;
    std::shared_ptr<boost::asio::io_context> m_io_context;

    mutable std::mutex m_socket_mutex;
    std::shared_ptr<boost::asio::ip::tcp::socket> m_socket;
};

}   // !models;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_CLIENTMODEL_HPP;