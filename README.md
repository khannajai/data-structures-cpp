![Build Status](https://travis-ci.com/khannajai/data-structures-cpp.svg?branch=master)

# Data Structures in C++
Some elementary data structures in C++. This project also serves as an example for a simple C++ project that uses CMake for building and installing, gtest and CTest for testing, Doxygen for documentation, Travis for CI and build status, pkg-config for packaging. 

## How to build, install, and uninstall:
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
cmake --build . 
```

3. Install shared libraries, docs and headers
```
sudo cmake --build . --target install
```
By default, on linux systems, this will install the include directory in ```/usr/local/include/``` and the shared libraries in ```/usr/local/lib/```. It will also install a pkgconfig file in ```usr/local/share/pkgconfig/```, which makes it easy for the user to use the library in other projects. To change the installation prefix (default is ```/usr/local```), run the first cmake command along with the option ```-DCMAKE_INSTALL_PREFIX=/my/new/path```.

4. Uninstall shared libraries, docs and headers
```
sudo cmake --build . --target uninstall
```

## How to use library in other projects
Once the user has installed the headers, the shared libraries, and the pkgconfig file, the user can now include the headers in their source code and link the shared libraries in other projects. 
To see all the linker flags to link the libraries:
```
pkg-config --libs data-structures-cpp
```
To include the headers, for example the user can do ```#include <data-structures-cpp/fraction.h>```.

To use the library in a CMake project, the user should search for the pkgconfig module by using pkgconfig in their ```CMakeLists.txt```. See the example here https://github.com/khannajai/use-data-struct