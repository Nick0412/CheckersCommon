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