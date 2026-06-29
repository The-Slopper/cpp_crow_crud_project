# Cpp Crow Crud - (c) 2026 Example Org - MIT License
# Author: Engineering Team <engineering@example.com>
cmake_minimum_required(VERSION 3.27)
project(cpp_crow_crud_project
        VERSION 1.0.0
        DESCRIPTION "Registration service (CRUD) with persistence, validation, and REST API."
        HOMEPAGE_URL "https://git.example.com/cpp-crow-crud-project"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

file(GLOB SOURCES src/*.cpp)
add_executable(app ${SOURCES})

enable_testing()
add_test(NAME unit COMMAND app)
