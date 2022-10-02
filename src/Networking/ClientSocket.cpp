#include "Networking/ClientSocket.h"
#include "StringUtils/StringFormat.h"
#include <string.h>

namespace Networking
{
    ClientSocket::ClientSocket(Address& endpoint, SocketType sockType, IpType ipType)
    : SendReceiveSocket{socket(ipType, sockType, 0)}
    {
        auto connectResult = connect(socketFileDescriptor, endpoint.pointer(), endpoint.size());

        if (connectResult == -1)
        {
            std::string errorMessage = StringUtils::StringFormat("Failed to connect client socket, errno=%d, message=%s", errno, strerror(errno));
            throw std::runtime_error(errorMessage);
        }
    }
}