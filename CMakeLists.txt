cmake_minimum_required(VERSION 3.20)

project(CheckersCommon)

add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(include)

add_library(Networking STATIC
    "src/Networking/Address.cpp"
    "src/Networking/ClientSocket.cpp"
    "src/Networking/SendReceiveSocket.cpp"
    "src/Networking/Socket.cpp"
    "src/Networking/SendReceiveSocket.cpp"
)