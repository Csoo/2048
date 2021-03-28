cmake_minimum_required(VERSION 3.0.0)
project(evolv_2048 VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories(src/shared)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/2048/*.cpp src/Player/*.cpp)

add_executable(evolv_2048 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
