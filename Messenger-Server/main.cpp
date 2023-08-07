#include "ServerController.hpp"
#include "ServerModel.hpp"

#include <boost/asio/io_context.hpp>

#include <memory>
#include <iostream>

int main(int argc, char **argv) {
    using namespace bukhtagram::ms::server;

    auto io_context = std::make_shared<boost::asio::io_context>();

    auto server_model = std::make_shared<models::ServerModel>(io_context);
    server_model->update_acceptor(12345);
    auto server_controller = std::make_shared<controllers::ServerController>(server_model);

    try {
        server_controller->run("127.0.0.1", 12345);
        io_context->run();
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}