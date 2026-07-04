cmake_minimum_required(VERSION 3.10)

project(ProjectCppEngine)

set(CMAKE_CXX_STANDARD 17)

# Engine sources
file(GLOB_RECURSE ENGINE_SOURCES
    engine/src/*.cpp
)

# Game sources
file(GLOB_RECURSE GAME_SOURCES
    game/src/*.cpp
)

# Engine library
add_library(engine
    ${ENGINE_SOURCES}
)

target_include_directories(engine PUBLIC engine/include)

# Game executable
add_executable(game
    ${GAME_SOURCES}
)

target_link_libraries(game PRIVATE winmm engine dbghelp)