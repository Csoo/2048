cmake_minimum_required(VERSION 3.1.0)
project(
    evolv_2048
    VERSION 0.1.0
    LANGUAGES CXX    
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_EXTENSIONS OFF)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    include(CTest)
endif()

add_subdirectory(shared)
add_subdirectory(app)
add_subdirectory(src)

target_include_directories(game PUBLIC src)
target_include_directories(shared INTERFACE shared)
