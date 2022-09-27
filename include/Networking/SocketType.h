#ifndef SOCKET_TYPE_H
#define SOCKET_TYPE_H

#include <sys/socket.h>

namespace Networking
{
    enum SocketType : int
    {
        TCP = SOCK_STREAM,
        UDP = SOCK_DGRAM
    };
}

#endif