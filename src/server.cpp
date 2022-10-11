#include <iostream>
#include "Networking/ServerSocket.h"
#include <string>

int main()
{
    try
    {
        // Networking::Address a("172.18.0.1", 34000);
        Networking::Address a(34000);
        Networking::ServerSocket server = Networking::ServerSocket::Builder()
            .withAddress(a)
            .withIpType(Networking::IpType::IPv4)
            .withSocketType(Networking::SocketType::TCP)
            .withNumberOfConnections(2)
            .build();

        auto connected = server.getConnectedSocket();
        auto data = connected.receiveData(5);

        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << "Data Value: " << (int)data[i] << " Char: " << (char)data[i] << "\n";
        }

        std::cout << std::string(data.begin(), data.end()) << "\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}