add_executable(app main.cpp)

target_compile_features(app PUBLIC cxx_std_11)
target_link_libraries(app PUBLIC shared)
target_link_libraries(app PUBLIC game)