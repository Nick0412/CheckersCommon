#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include "Socket.h"
#include "Address.h"
#include "SendReceiveSocket.h"

namespace Networking
{
    class ServerSocket : public Socket
    {
    public:
        ServerSocket() = delete;
        SendReceiveSocket getConnectedSocket();

        class ServerSocketBuilder
        {
        private:
            Address address;
            SocketType sockType;
            IpType ipType;
            int numberOfConnections;

        public:
            ServerSocketBuilder& withAddress(const Address& address);
            ServerSocketBuilder& withSocketType(const SocketType& sockType);
            ServerSocketBuilder& withIpType(const IpType& ipType);
            ServerSocketBuilder& withNumberOfConnections(int numberOfConnections);
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