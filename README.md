# Overview
This repository is hold the common code that will be used between the CheckersClient and CheckersServer. It provides commonly needed utilities such as string utilities, shared exceptions, networking, and more.

# Requirements
1. C++ compiler (Clang, GCC)
2. CMake
3. Conan

# Build Instructions
```
mkdir build
cd build
conan install ..
cmake ..
cmake --build .
```