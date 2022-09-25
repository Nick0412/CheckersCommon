#ifndef IP_TYPE_H
#define IP_TYPE_H

#include <sys/socket.h>

namespace Networking
{
    enum IpType : int
    {
        IPv4 = AF_INET,
        IPv6 = AF_INET6
    };
}

#endif