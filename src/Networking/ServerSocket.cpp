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

    ServerSocket::ServerSocketBuilder ServerSocket::Builder()
    {
        return ServerSocketBuilder();
    }

    ServerSocket::ServerSocketBuilder& ServerSocket::ServerSocketBuilder::withAddress(const Address& address)
    {
        this->address = address;
        return *this;
    }

    ServerSocket::ServerSocketBuilder& ServerSocket::ServerSocketBuilder::withSocketType(const SocketType& sockType)
    {
        this->sockType = sockType;
        return *this;
    }

    ServerSocket::ServerSocketBuilder& ServerSocket::ServerSocketBuilder::withIpType(const IpType& ipType)
    {
        this->ipType = ipType;
        return *this;
    }

    ServerSocket::ServerSocketBuilder& ServerSocket::ServerSocketBuilder::withNumberOfConnections(int numberOfConnections)
    {
        this->numberOfConnections = numberOfConnections;
        return *this;
    }

    ServerSocket ServerSocket::ServerSocketBuilder::build()
    {
        return ServerSocket(address, sockType, ipType, numberOfConnections);
    }
}