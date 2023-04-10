cmake_minimum_required(VERSION 3.10)
project(TTEngine)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (WIN32)
    add_definitions(-DRUNNING_PLATFORM_WINDOWS)
endif()

add_definitions(-DBUILD_DLL)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})