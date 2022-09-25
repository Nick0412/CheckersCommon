#include "Networking/Address.h"
#include <arpa/inet.h>

namespace Networking
{
    Address::Address()
    {

    }

    Address::Address(const std::string& ipAddress, uint16_t port, IpType type)
    {
        address.sin_family = type;
        address.sin_port = ConvertPortToNetworkShort(port);
        address.sin_addr = ConvertIpAddressToNetworkAddress(ipAddress);
    }

    std::string Address::getIpAddress() const
    {
        char* ipAddressPointer = inet_ntoa(address.sin_addr);
        return std::string(ipAddressPointer);
    }

    uint16_t Address::getPort() const
    {
        return ntohs(address.sin_port);
    }

    std::size_t Address::size() const
    {
        return sizeof(address);
    }

    struct sockaddr* Address::pointer()
    {
        return reinterpret_cast<struct sockaddr*>(&address);
    }

    const struct sockaddr* Address::constPointer()
    {
        auto sockAddrCast = reinterpret_cast<struct sockaddr*>(&address);
        return const_cast<const struct sockaddr*>(sockAddrCast);
    }

    uint16_t Address::ConvertPortToNetworkShort(uint16_t port)
    {
        return htons(port);
    }

    struct in_addr Address::ConvertIpAddressToNetworkAddress(const std::string& ipAddress)
    {
        struct in_addr tempNetworkAddress;
        inet_aton(ipAddress.c_str(), &tempNetworkAddress);

        return tempNetworkAddress;
    }

    void Address::SetIpAddress(struct in_addr& networkAddress, const std::string& ipAddress)
    {
        inet_aton(ipAddress.c_str(), &networkAddress);
    }

    std::ostream& operator<<(std::ostream& outputStream, const Address& a)
    {
        outputStream << "{ IP Address: " << a.getIpAddress()
                     << ", Port: " << a.getPort() << " }";
        return outputStream;
    }
}