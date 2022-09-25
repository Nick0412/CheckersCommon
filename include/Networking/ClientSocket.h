#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include "SendReceiveSocket.h"
#include "Address.h"

namespace Networking
{
    /**
     * @class ClientSocket
     *
     * When a ClientSocket is constructed it tries to connect to the address right away and form a connection.
     */
    class ClientSocket : public SendReceiveSocket
    {
    public:
        ClientSocket() = delete;
        ClientSocket(Address& endpoint, SocketType sockType = SocketType::TCP, IpType ipType = IpType::IPv4);
    };
}

#endif