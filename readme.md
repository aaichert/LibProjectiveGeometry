# Projective Geometry of Two- and Three-Space

Created by Andre Aichert, aaichert@gmail.com, andre.aichert@fau.de

This project provides Eigen-based types and functions for 2D and 3D projective geometry.

The projects contained in this repository use the CMake build environment. You can use CMake to generate Visual Studio projects for Windows or makefiles for Linux and MacOS. All libraries used are available on all three platforms and the projects should build with very few fixes in source code.


# Building using Microsoft Windows, Visual Studio and CMake.

I'm sure Linux folks will manage on their own.

Prerequisites
```
- VisualStudio
- CMake https://cmake.org/
- Eigen http://eigen.tuxfamily.org/
```


## Building LibProjectiveGeometry

1. Step   I,   Uncompress the LibProjectiveGeometry sources
```
            (example:)
                C:/Development/LibProjectiveGeometry
```
2. Step   II,  Run Cmake GUI and specify your LibProjectiveGeometry directory and a build directory
```
            (example:)
                Where is the source code: -> C:/Development/LibProjectiveGeometry
		        Where to build the binaries:  -> C:/Development/LibProjectiveGeometry/build
```
3. Step   III, Click Configure and select your version of Visual Studio.
5. Step   V,    Make sure Eigen was found.
```
            (example:)
                EIGEN_INCLUDE_DIR -> C:/Development/extern/eigen-3.3.3
```
6. Step  VI,   Click Configure and Generate again. Open your LibProjectiveGeometry/build/LibProjectiveGeometry.sln in Visual Studio.
7. Step  VII,  In the Solution Explorer, right-click the "INSTALL" project and select "Build". (This is the debug build) Change your configuration type to Release in the Configuration Manager and build project "INSTALL" again

At this point, anyone with the same compiler (i.e. version of Visual Studio) will be able to use LibProjectiveGeometry if you send them ONLY the directory that you specified as CMAKE_INSTALL_PREFIX. As mentioned earlier, see also https://chadaustin.me/cppinterface.html for more info.
```
(example:)
    compress the directory "C:/Development/LibProjectiveGeometry/export" and send compressed file by mail.
```

## Notes

# Notes on using Eigen
The Eigen library is entirely header-only. There have been breaking changes since version 3.3 . To prevent linking errors when building this repo, please resort to using this old version here: https://gitlab.com/libeigen/eigen/-/releases/3.3.0


# Notes on using LibProjectiveGeometry from a different project

Section 3) mentions, that it is possibly to ship LibProjectiveGeometry just by copying the files in the install directory. Setting up a project with CMake that includes LibProjectiveGeometry should be straight-forward.

1. Step   I,   Create your c++ file (example: main.cpp)
2. Step   II,  Create a CMakeLists.txt file and add the following information to it:
```
            cmake_minimum_required(VERSION 3.5.2)
			project(PG_Test)
            find_package(LibProjectiveGeometry)
            find_package(LibProjectiveGeometry)
			add_executable(PG main.cpp)
			target_link_libraries(PG LibProjectiveGeometry LibProjectiveGeometry)
```
3. Step   III, Run Cmake GUI and specify your source directory and a build directory as always.
4. Step IV,    Click Configure and set LibProjectiveGeometry_DIR to where you placed the library
```
 			(example:)
			    LibProjectiveGeometry_DIR -> C:/Development/extern/LibProjectiveGeometry
```
5. Step  V,    Click Configure and Generate again. Open your build/PG_Test.sln in Visual Studio. And have fun.

