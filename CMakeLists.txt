cmake_minimum_required(VERSION 3.0.0)
project(The_c_book VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(The_c_book main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
