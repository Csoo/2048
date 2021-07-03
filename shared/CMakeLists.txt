
add_library(shared INTERFACE)

target_compile_features(shared INTERFACE cxx_std_11)
target_sources(shared INTERFACE ${evolv_2048_SOURCE_DIR}/shared/enums/direction.h)