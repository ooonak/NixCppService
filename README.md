# NixCppService
Learning Nix, dummy project with a Docker based C++ service.

## Build, test, install by hand
The old way.
```bash
$ mkdir build; cd build
$ cmake -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug ..
$ cmake --build .
$ ctest
$ cmake --install . --prefix $HOME/usr/local
```

...or modern CMake.

```bash
$ cmake -S. -B build -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$HOME/usr/local
$ cmake --build build
$ cd build; ctest; cd ..
$ cmake --install build
```
