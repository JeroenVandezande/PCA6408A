cmake_minimum_required(VERSION 3.19)
project(PCA6408A C)

set(CMAKE_C_STANDARD 99)

include(cpm/CPM.cmake)
CPMAddPackage("gh:JeroenVandezande/LowLevelCInterfaces@1.2.0")

add_library(${PROJECT_NAME} PCA6408A.c PCA6408A.h)

target_link_libraries(${PROJECT_NAME} LowLevelCInterfaces)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})