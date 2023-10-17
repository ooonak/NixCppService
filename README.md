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

### Create package for use with FetchContent
```bash
$ cmake --build build --target CppServicePackage
[1/1] Generating CppService-src.zip

# Then in consuming project
include(FetchContent)
...
FetchContent_Declare(CppService URL https://some-path/CppService-src.zip)
FetchContent_MakeAvailable(CppService)
...
target_link_libraries(${PROJECT_NAME} PRIVATE CppService::CppService)
```
