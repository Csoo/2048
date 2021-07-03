add_library(game)

target_sources(game
    PRIVATE
        ${evolv_2048_SOURCE_DIR}/src/2048/game.cpp
        ${evolv_2048_SOURCE_DIR}/src/Player/player.cpp
    PUBLIC
        ${evolv_2048_SOURCE_DIR}/src/2048/game.h
        ${evolv_2048_SOURCE_DIR}/src/Player/player.h
)

target_compile_features(game PUBLIC cxx_std_11)

target_link_libraries(game PRIVATE shared)