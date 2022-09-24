#ifndef STRING_FORMAT_H
#define STRING_FORMAT_H

#include <string>
#include <cstdio>
#include <stdexcept>
#include <memory>
#include <iostream>

namespace StringUtils
{
    namespace Internals
    {
        template <typename ... Args>
        int getNumberOfBytesForFormattedString(const std::string& format, Args ... args)
        {
            auto numberOfBytes = snprintf(nullptr, 0, format.c_str(), args ...) + 1;
            if (numberOfBytes <= 0)
            {
                throw std::runtime_error("Could not format string.");
            }
            return numberOfBytes;
        }
    }

    template <typename ... Args>
    std::string StringFormat(const std::string& format, Args ... args)
    {
        auto numberOfBytes = Internals::getNumberOfBytesForFormattedString(format, args ...);
        std::size_t size = static_cast<std::size_t>(numberOfBytes);
        std::unique_ptr<char[]> buffer = std::make_unique<char[]>(size);

        // Load format into a correctly sized buffer.
        snprintf(buffer.get(), size, format.c_str(), args ...);
        return std::string(buffer.get(), buffer.get() + size - 1);
    }
}

#endif