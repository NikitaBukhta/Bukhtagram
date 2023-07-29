#ifndef BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_CLIENTMODEL_HPP
#define BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_CLIENTMODEL_HPP

#include "IClientModel.hpp"

namespace bukhtagram {
namespace mc {
namespace client {
namespace models {

class ClientModel : public IClientModel {
public:
    ClientModel(void) = default;
    virtual ~ClientModel(void) = default;
};

}   // !models;
}   // !client;
}   // !mc;
}   // !bukhtagram;

#endif  // !BUKHTAGRAM_MESSENGERCLIENT_CLIENT_MODELS_CLIENT_CLIENTMODEL_HPP;