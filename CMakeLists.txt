cmake_minimum_required (VERSION 2.6)
add_compile_options(-std=c++11)
project (MemoryPool)

add_executable(
    main 
    test.cpp
    MemoryPool.h
    MemoryPool.cpp
)

