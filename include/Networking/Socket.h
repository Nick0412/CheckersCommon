#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <SocketType.h>
#include <IpType.h>

namespace Networking
{
    /**
     * @class Socket
     *
     * Wrapper class around a socket file descriptor. This class performs RAII and will close
     * its socket upon being destructed. Because of this, we delete the copy constructor and
     * copy assignment.
     */
    class Socket
    {
    public:
        Socket() = delete;
        Socket(const Socket& other) = delete;
        Socket& operator=(const Socket& other) = delete;

        Socket(SocketType type = SocketType::TCP, IpType ipType = IpType::IPv4);
        Socket(int fileDescriptor);
        ~Socket();

    protected:
        int socketFileDescriptor;
    };
}

#endif