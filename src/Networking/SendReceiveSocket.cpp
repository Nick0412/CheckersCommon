#include "Networking/SendReceiveSocket.h"

namespace Networking
{
    SendReceiveSocket::SendReceiveSocket(int socketFileDescriptor)
    : Socket{socketFileDescriptor}
    {

    }

    void SendReceiveSocket::sendData(const ByteVector& byteData)
    {
        auto numBytesToSend = byteData.size();
        size_t bytesSent = 0;

        while (bytesSent < numBytesToSend)
        {
            auto offsetInData = byteData.data() + bytesSent;
            auto remainingNumberOfBytes = numBytesToSend - bytesSent;

            bytesSent += send(socketFileDescriptor, offsetInData, remainingNumberOfBytes, 0);
        }
    }

    SendReceiveSocket::ByteVector SendReceiveSocket::receiveData(size_t bytesToReceive)
    {
        ByteVector dataToReturn(bytesToReceive);
        size_t bytesRead = 0;

        while (bytesRead < bytesToReceive)
        {
            auto offsetInData = dataToReturn.data() + bytesRead;
            auto remainingNumberOfBytes = bytesToReceive - bytesRead;

            bytesRead += recv(socketFileDescriptor, offsetInData, remainingNumberOfBytes, 0);
        }
    }
}