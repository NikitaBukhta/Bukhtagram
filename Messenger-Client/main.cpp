#include "ClientModel.hpp"
#include "ClientController.hpp"

#include <iostream>
#include <memory>

int main(int argc, char **argv) {
    using namespace bukhtagram::mc::client;

    std::cout << "Started program" << std::endl;
    auto io_context = std::make_shared<boost::asio::io_context>();
    auto client_model = std::make_shared<models::ClientModel>();
    client_model->set_io_context(io_context);
    client_model->update_socket();

    std::cout << "Client socket is set" << std::endl;
    
    auto client_controller = std::make_shared<controllers::ClientController>(
        client_model
    );
    client_controller->connect_to("127.0.0.1", 12345);
    
    return 0;
}