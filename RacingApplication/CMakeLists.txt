cmake_minimum_required(VERSION 3.10)

project(RacingApplication)

include_directories(${CMAKE_SOURCE_DIR}/../TTEngine/include)
if(WIN32)
    add_definitions(-DRUNNING_PLATFORM_WINDOWS)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} TTEngine)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../TTEngine/build)