# Tc-wpr (Tiny curl wrapper)
## tiny curl wrapper in c++ 20

<img src="img/net.jpg" width="400" height="200">

### Dependencies
- cmake 3.22.2
- boost 1.76
- libcurl4

#### Description of the project
* bin: contains examples that uses the curl wrapper
* lib: contains all the libraries
* nrtest: contains a set of unitary tests
* rc: resources
* include: API
* src: contains the sources

#### How to build the project?
```
 mkdir build
 cd build
 cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-11 (in release)
 cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-11 (in Debug)

```
