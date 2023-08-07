#include "ServerModel.hpp"



namespace bukhtagram {
namespace ms {
namespace server {
namespace models {

ServerModel::ServerModel(std::weak_ptr<boost::asio::io_context> val) {
    set_io_contex(val);
    update_acceptor();
}

/*
 * Getters starts;
 */

std::weak_ptr<boost::asio::io_context> ServerModel::io_context(void) {
    std::lock_guard<std::mutex> guard(m_io_context_mutex);
    return m_io_context;
}

std::weak_ptr<boost::asio::ip::tcp::acceptor> ServerModel::acceptor(void) {
    std::lock_guard<std::mutex> guard(m_accpetor_mutex);
    return m_acceptor;
}

/*
 * Getters ends;
 */

/*
 * Setters starts;
 */


bool ServerModel::set_io_contex(std::weak_ptr<boost::asio::io_context> val) {
    std::lock_guard<std::mutex> guard(m_io_context_mutex);
    auto new_ptr = val.lock();

    if (new_ptr.get() && new_ptr.get() != m_io_context.get()) {
        m_io_context = new_ptr;
        return true;
    }
    return false;
}

/*
 * Setters ends;
 */

/*
 * Update methods starts;
 */

bool ServerModel::update_acceptor(void) {
    std::lock_guard<std::mutex> io_context_guard(m_io_context_mutex);
    if (m_io_context.get()) {
        std::lock_guard<std::mutex> acceptor_guard(m_accpetor_mutex);
        m_acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(*m_io_context);
        return true;
    }
    return false;
}

/*
 * Update methods ends;
 */

}   // !models;
}   // !server;
}   // !ms;
}   // !bukhtagram;