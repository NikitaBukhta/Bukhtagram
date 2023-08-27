#include "ClientView.hpp"
#include "Logger.hpp"

namespace bukhtagram {
namespace mc {
namespace client {
namespace views {

ClientView::ClientView(std::weak_ptr<boost::asio::io_context> io_context_weak) {
    DECLARE_TAG_SCOPE;
    LOG_INFO << "called";
    auto io_context = io_context_weak.lock();

    m_client_model = std::make_shared<models::ClientModel>(io_context);
    m_client_controller = std::make_shared<controllers::ClientController>(m_client_model);
}

bool ClientView::run(const std::string &address, uint16_t port) {
    DECLARE_TAG_SCOPE;
    LOG_INFO << "address: " << address << "; port: " << port;

    if (!m_client_controller->connect_to(address, port)) {
        LOG_ERROR << "failed to connect!";
        return false;
    }

    m_client_controller->run();

    return true;
};

}   // !views;
}   // !client;
}   // !mc;
}   // !bukhtagram;