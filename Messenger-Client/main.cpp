#include "ClientModel.hpp"
#include "ClientController.hpp"

#include <iostream>
#include <memory>

int main(int argc, char **argv) {
    using namespace bukhtagram::mc::client;

    auto client_model = std::make_shared<models::ClientModel>();
    auto client_controller = std::make_shared<controllers::ClientController>(
        client_model
    );
    
    return 0;
}