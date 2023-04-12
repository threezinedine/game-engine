cmake_minimum_required(VERSION 3.10)
project(TTEngine)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw)

if (WIN32)
    add_definitions(-DRUNNING_PLATFORM_WINDOWS)
endif()

add_definitions(-DBUILD_DLL)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
# target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/PrecompileHeader.hpp)
target_link_libraries(${PROJECT_NAME} spdlog)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/build/vendor/spdlog)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/build/vendor/glfw)