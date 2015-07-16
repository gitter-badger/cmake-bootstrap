# CMake Bootstrap

[![Join the chat at https://gitter.im/gumbit/cmake-bootstrap](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/gumbit/cmake-bootstrap?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

C/C++ project bootstrap using CMake.

To build this project, run the following commands from the project's root directory:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make test
```

You can use any IDE of your choice to edit source files. However, currently only the JetBrains CLion IDE will give you
a full integration with your CMake project. Since, CMake generates make files, any IDE that supports make file projects
can be used with CMake (e.g. Eclipse CDT), but you will have to run CMake manually. Never the less, you can always fall
back to command line, since it is very easy to build CMake projects by hand.