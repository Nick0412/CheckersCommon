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
# Replace path gcc version 11 location
export CC=/usr/bin/gcc-11
# Replace path g++ version 11 location
export CXX=/usr/bin/g++-11
conan install ..
cmake ..
cmake --build .
```

# Current Conan Profile
```
[settings]
os=Linux
os_build=Linux
arch=x86_64
arch_build=x86_64
compiler=gcc
compiler.version=11
compiler.libcxx=libstdc++11
build_type=Release
[options]
[build_requires]
[env]
```