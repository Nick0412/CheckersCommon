#include "Networking/ServerSocket.h"
#include "StringUtils/StringFormat.h"
#include <string.h>

namespace Networking
{
    ServerSocket::ServerSocket(Address& address, SocketType sockType, IpType ipType, int numberOfConnections)
    : Socket(sockType, ipType)
    {
        auto bindResult = bind(socketFileDescriptor, address.constPointer(), address.size());
        if (bindResult == -1)
        {
            std::string errorMessage = StringUtils::StringFormat("Failed to bind server socket, errno=%d, message=%s", errno, strerror(errno));
            throw std::runtime_error(errorMessage);
        }

        auto listenResult = listen(socketFileDescriptor, numberOfConnections);
        if (listenResult == -1)
        {
            std::string errorMessage = StringUtils::StringFormat("Failed to listen on server socket, errno=%d, message=%s", errno, strerror(errno));
            throw std::runtime_error(errorMessage);
        }
    }

    SendReceiveSocket ServerSocket::getConnectedSocket()
    {
        Address temp;
        socklen_t size = temp.size();
        auto connectedSocketFileDescriptor = accept(socketFileDescriptor, temp.pointer(), &size);

        if (connectedSocketFileDescriptor == -1)
        {
            std::string errorMessage = StringUtils::StringFormat("Failed to accept socket, errno=%d, message=%s", errno, strerror(errno));
            throw std::runtime_error(errorMessage);
        }

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