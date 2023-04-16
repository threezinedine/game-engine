cmake_minimum_required(VERSION 3.24.1)
project(GLAD)


include_directories(include)

add_library(${PROJECT_NAME} STATIC src/glad.c)