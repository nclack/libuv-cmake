Instructions
------------

1. Clone this repository, and cd to it in a console
2. Download the libuv repository using

        git submodule update --init

3. build 

   For example,

        mkdir build
        cd build
        cmake ..
        make

I've added a couple things to make it simple to
get this library into your other cmake projects.  Use 
something like the following in your CMakeLists.txt.

        ...
        find_package(uv)
        add_executable(example ${SRCS}) # for example
        target_add_uv(example)
        ...
        
This works because

1. CMake's package registry[1] feature 
   helps find_package find your build directory.

2. A script, `uv-config.cmake`, is run by `find_package()`.
   It defineds the `target_add_uv()` function.  That takes
   your target and ammends the target properties so it
   links libuv, any system dependencies and adds include
   directories.

[1]: http://www.cmake.org/Wiki/CMake/Tutorials/Package_Registry        

Originally by David Capello. 
Modified by Nathan Clack.
