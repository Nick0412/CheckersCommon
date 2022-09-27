#ifndef SEND_RECEIVE_SOCKET_H
#define SEND_RECEIVE_SOCKET_H

#include "Socket.h"
#include <vector>
#include <cstdint>

namespace Networking
{
    /**
     * @class SendReceiveSocket
     *
     * A send receive socket is similar to a socket except is supports the ability to
     * send and receive data over the underlying socket file descriptor. Because it inherits
     * from the socket class, we need allow this socket to be constructed given a socket file
     * descriptor.
     *
     * This class will be used in the context of a client socket, as well as a socket that is
     * returned by a server socket when the accept function is called.
     */
    class SendReceiveSocket : public Socket
    {
    protected:
        using ByteVector = std::vector<uint8_t>;

    public:
        SendReceiveSocket() = delete;
        SendReceiveSocket(int socketFileDescriptor);

        void sendData(const ByteVector& data);
        ByteVector receiveData(size_t bytesToReceive);
    };
}

#endif