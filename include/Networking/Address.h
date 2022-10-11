#ifndef ADDRESS_H
#define ADDRESS_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <ostream>
#include "IpType.h"

namespace Networking
{
    /**
     * @class Address
     *
     * The Address class is used to represent a combination of IP address and port number
     * that a connection will hit.
     */
    class Address
    {
    public:
        Address();
        Address(const std::string& ipAddress, uint16_t port, IpType type = IpType::IPv4);
        Address(uint16_t port, IpType type = IpType::IPv4);
        std::string getIpAddress() const;
        uint16_t getPort() const;
        std::size_t size() const;
        struct sockaddr* pointer();
        const struct sockaddr* constPointer();

    public:
        // Helpful method for printing out details of an address.
        friend std::ostream& operator<<(std::ostream& outputStream, const Address& a);

    private:
        // Helper methods used to build the underlying sockaddr_in.
        static uint16_t ConvertPortToNetworkShort(uint16_t port);
        static struct in_addr ConvertIpAddressToNetworkAddress(const std::string& ipAddress);
        static void SetIpAddress(struct in_addr& networkAddress, const std::string& ipAddress);

    private:
        struct sockaddr_in address;
    };
}

#endif