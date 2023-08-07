#ifndef BUKHTAGRAM_MESSENGERSERVER_SERVER_MODELS_ISERVERMODELS_HPP
#define BUKHTAGRAM_MESSENGERSERVER_SERVER_MODELS_ISERVERMODELS_HPP

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <inttypes.h>

namespace bukhtagram {
namespace ms {
namespace server {
namespace models {

class IServerModel {
public:
    // Getters starts;

    virtual std::weak_ptr<boost::asio::io_context> io_context(void) = 0;
    virtual std::weak_ptr<boost::asio::ip::tcp::acceptor> acceptor(void) = 0;

    // Getters ends;

    // Setters starts;

    virtual bool set_io_contex(std::weak_ptr<boost::asio::io_context> val) = 0;
    
    // Setters ends;

    // Update methods starts;

    virtual bool update_acceptor(void) = 0;

    // Update methods ends;
};

}   // !models;
}   // !server;
}   // !ms;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERSERVER_SERVER_MODELS_ISERVERMODELS_HPP;