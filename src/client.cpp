#include <iostream>
#include "Networking/ClientSocket.h"
#include <vector>
#include <cstdint>

int main()
{
    try
    {
        Networking::Address a("127.0.0.1", 34000);
        Networking::ClientSocket client(a);
        std::vector<uint8_t> data = {'h', 'e', 'l', 'l', 'o'};
        client.sendData(data);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}