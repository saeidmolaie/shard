cmake_minimum_required(VERSION 3.16)

project(shard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(
    shard
    src/Shard.cpp
    src/Argument/ArgumentParser.cpp
    src/Argument/ArgumentValidator.cpp
)

target_include_directories(
    shard PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)