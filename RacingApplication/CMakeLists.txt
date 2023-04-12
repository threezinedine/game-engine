cmake_minimum_required(VERSION 3.24.1)

project(RacingApplication)

include_directories(
    ${CMAKE_SOURCE_DIR}/../TTEngine/include
    ${CMAKE_SOURCE_DIR}/../TTEngine/vendor/spdlog/include
)
link_directories(${CMAKE_SOURCE_DIR}/../TTEngine/build)

if(WIN32)
    add_definitions(-DRUNNING_PLATFORM_WINDOWS)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC TTEngine)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/../TTEngine/build)