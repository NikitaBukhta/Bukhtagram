#include "ClientModel.hpp"

#include <iostream>

namespace bukhtagram {
namespace mc {
namespace client {
namespace models {

/*
 *  Getters starts;
 */

std::weak_ptr<boost::asio::io_context> ClientModel::io_context(void) const {
    std::lock_guard<std::mutex> guard(m_io_context_mutex);
    return m_io_context;
}

std::weak_ptr<boost::asio::ip::tcp::socket> ClientModel::socket(void) const {
    std::lock_guard<std::mutex> guard(m_socket_mutex);
    return m_socket;
}

/*
 *  Getters ends;
 */

/*
 *  Setters starts;
 */

bool ClientModel::set_io_context(std::weak_ptr<boost::asio::io_context> val) {
    std::lock_guard<std::mutex> guard(m_io_context_mutex);
    auto new_ptr = val.lock();
    if (new_ptr.get() && m_io_context.get() != new_ptr.get()) {
        m_io_context = new_ptr;
        return true;
    }
    return false;
}

/*
 *  Setters ends;
 */

/*
 *  Other methods starts;
 */

bool ClientModel::update_socket(void) {
    std::lock_guard<std::mutex> guard(m_io_context_mutex);
    if (m_io_context.get()) {
        std::lock_guard<std::mutex> guard(m_socket_mutex);
        m_socket = std::make_shared<boost::asio::ip::tcp::socket>(*m_io_context);
        return true;
    }
    return false;
}

/*
 *  Other methods ends;
 */

}   // !models;
}   // !client;
}   // !mc;
}   // !bukhtagram;