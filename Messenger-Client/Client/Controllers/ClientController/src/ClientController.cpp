#include "ClientController.hpp"

namespace bukhtagram {
namespace mc {
namespace client {
namespace controllers {

ClientController::ClientController(std::weak_ptr<models::IClientModel> client_model)
    : m_client_model(client_model.lock())
{

}

}   // !controllers;
}   // !client;
}   // !mc;
}   // !bukhtagram;