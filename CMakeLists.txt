cmake_minimum_required(VERSION 3.19)
project(PCA6408A C)

set(CMAKE_C_STANDARD 99)

include(cpm/CPM.cmake)
CPMAddPackage("gh:JeroenVandezande/LowLevelCInterfaces@1.1.0")

add_library(PCA6408A PCA6408A.c PCA6408A.h)

target_link_libraries(${PROJECT_NAME} LowLevelCInterfaces)

target_include_directories (PCA6408A PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})