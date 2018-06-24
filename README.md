![Build Status](https://travis-ci.com/khannajai/data-structures-cpp.svg?branch=master)

# Data Structures in C++
Some elementary data structures in C++

## How to build and install:
1. Clone respository
```
git clone https://github.com/khannajai/data-structures-cpp.git
```

2. Create build directory inside repository and change to it
```
cd data-structures-cpp
mkdir build
cd build
```

3. Build and libraries and test executables
```
cmake ..
cmake --build . --target all
```

4. Install shared libraries and headers
```
sudo make install
```
By default, on linux systems, this will install the headers in ```/usr/local/include/data-structures.cpp``` and the shared libraries in ```/usr/local/lib/```. It will also install a pkgconfig file in ```usr/local/share/pkgconfig/```, which makes it easy for the user to use the library in other projects.


## How to use library in other projects
Once installed, the user can link the libraries