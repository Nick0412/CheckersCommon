#include "Networking/ServerSocket.h"

namespace Networking
{
    ServerSocket::ServerSocket(Address& address, SocketType sockType, IpType ipType, int numberOfConnections)
    : Socket(sockType, ipType)
    {
        bind(socketFileDescriptor, address.constPointer(), address.size());
        listen(socketFileDescriptor, numberOfConnections);
    }

    SendReceiveSocket ServerSocket::getConnectedSocket()
    {
        Address temp;
        socklen_t size;
        auto connectedSocketFileDescriptor = accept(socketFileDescriptor, temp.pointer(), &size);

        return SendReceiveSocket(connectedSocketFileDescriptor);
    }
}