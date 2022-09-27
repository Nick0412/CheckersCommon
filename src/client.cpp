#include <iostream>
#include "Networking/ClientSocket.h"
#include <vector>
#include <cstdint>

int main()
{
    Networking::Address a("127.0.0.1", 34000);
    Networking::ClientSocket client(a);
    std::vector<uint8_t> data = {'h', 'e', 'l', 'l', 'o'};
    client.sendData(data);
    return 0;
}