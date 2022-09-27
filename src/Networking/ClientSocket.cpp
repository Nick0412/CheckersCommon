#include "Networking/ClientSocket.h"

namespace Networking
{
    ClientSocket::ClientSocket(Address& endpoint, SocketType sockType, IpType ipType)
    : SendReceiveSocket{socket(ipType, sockType, 0)}
    {
        connect(socketFileDescriptor, endpoint.pointer(), endpoint.size());
    }
}