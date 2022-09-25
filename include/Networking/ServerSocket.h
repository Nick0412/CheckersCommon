#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include "Socket.h"
#include "Address.h"
#include "SendReceiveSocket.h"

namespace Networking
{
    class ServerSocket : public Socket
    {
    private:
        int numberOfConnections;

    public:
        ServerSocket() = delete;
        SendReceiveSocket getConnectedSocket();

        class ServerSocketBuilder
        {
        private:
            Address address;
            SocketType sockType;
            IpType ipType;

        public:
            ServerSocketBuilder& address(Address& address);
            ServerSocketBuilder& socketType(SocketType& sockType);
            ServerSocketBuilder& ipType(IpType& ipType);
            ServerSocketBuilder& numberOfConnections(int& numberOfConnections);
            ServerSocket build();
        };

    public:
        static ServerSocketBuilder Builder();

    private:
        // To be called by the ServerSocketBuilder
        ServerSocket(Address& address, SocketType sockType, IpType ipType, int numberOfConnections);
    };
}

#endif