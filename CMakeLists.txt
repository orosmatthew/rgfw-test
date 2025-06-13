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

add_subdirectory(external/glad)
add_subdirectory(external/rgfw)

add_executable(rgfw_test src/main.cpp)
target_link_libraries(rgfw_test PRIVATE glad rgfw)