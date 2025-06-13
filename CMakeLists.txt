cmake_minimum_required(VERSION 3.10)
project(rgfw-test)
set(CMAKE_CXX_STANDARD 20)

if (WIN32 AND MINGW)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")
    endif ()
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -stdlib=libc++ -lc++ -lc++abi")
    endif ()
endif ()

add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

add_library(rgfw INTERFACE)
target_include_directories(rgfw INTERFACE external/rgfw/include)

add_executable(rgfw_test src/main.cpp)
target_link_libraries(rgfw_test PRIVATE glad rgfw)