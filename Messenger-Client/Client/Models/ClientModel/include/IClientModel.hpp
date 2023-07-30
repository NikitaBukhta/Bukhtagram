#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_ICLIENTMODEL_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_ICLIENTMODEL_HPP

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <memory>

namespace bukhtagram {
namespace mc {
namespace client {
namespace models {

class IClientModel {
public:
    // Getters starts;

    virtual std::weak_ptr<boost::asio::io_context> io_context(void) const = 0;
    virtual std::weak_ptr<boost::asio::ip::tcp::socket> socket(void) const = 0;

    // Getters ends;

    // Setters starts;

    virtual bool set_io_context(std::weak_ptr<boost::asio::io_context> val) = 0;

    // Setters ends;

    // Other methods starts;

    virtual bool update_socket(void) = 0;

    // Other methods ends;
};

}   // !models;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_ICLIENTMODEL_HPP;