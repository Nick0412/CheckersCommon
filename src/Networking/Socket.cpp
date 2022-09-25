#include <stdexcept>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "Networking/Socket.h"
#include "StringUtils/StringFormat.h"

namespace Networking
{
    Socket::Socket(int fileDescriptor)
    : socketFileDescriptor{fileDescriptor}
    {

    }

    Socket::Socket(SocketType type = SocketType::TCP, IpType ipType = IpType::IPv4)
    : socketFileDescriptor{socket(ipType, type, 0)}
    {
        if (socketFileDescriptor == -1)
        {
            std::string errorMessage = StringUtils::StringFormat("Failed to create socket, errno=%d, message=%s", errno, strerror(errno));
            throw std::runtime_error(errorMessage);
        }
    }

    Socket::~Socket()
    {
        close(socketFileDescriptor);
    }
}