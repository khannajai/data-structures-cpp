![Build Status](https://travis-ci.com/khannajai/data-structures-cpp.svg?branch=master)

# Data Structures in C++
Some elementary data structures in C++. This project also serves as an example for a simple C++ project that uses CMake for building and installing, gtest and CTest for testing, Doxygen for documentation, Travis for CI and build status, pkg-config for packaging. 

## How to build and install:
1. Clone respository, enter it, and then create build directory.
```
git clone https://github.com/khannajai/data-structures-cpp.git
cd data-structures-cpp
mkdir build
cd build
```

2. Build the shared libraries, docs and test executables
```
cmake ..
cmake --build . --target all
```

3. Install shared libraries, docs and headers
```
sudo make install
```
By default, on linux systems, this will install the include directory in ```/usr/local/include/``` and the shared libraries in ```/usr/local/lib/```. It will also install a pkgconfig file in ```usr/local/share/pkgconfig/```, which makes it easy for the user to use the library in other projects.

## How to use library in other projects
Once the user has installed the headers, the shared libraries, and the pkgconfig file, the user can now include the headers in their source code and link the shared libraries in other projects. 
To see all the linker flags to link the libraries:
```
pkg-config --libs data-structures-cpp
```
To include the headers, the user can do ```#include <data-structures-cpp/name_of_header.h>``` with the correct name of the header they want to use. 

To use the library in a CMake project, the user should search for the pkgconfig module by using pkgconfig in their ```CMakeLists.txt```. See the example here https://github.com/khannajai/use-data-struct