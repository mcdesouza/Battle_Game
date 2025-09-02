cmake_minimum_required(VERSION 3.31)
project(Battle_Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(SDL2_PATH "C:/Dev/SDL2-2.32.8/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SDL2_IMAGE_PATH "C:/Dev/SDL2_image-2.8.8/x86_64-w64-mingw32")

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(Battle_Game src/main.cpp
        src/game.cpp
        src/game.h
        src/arena/Arena.cpp
        src/arena/Arena.h
        src/utils/Utils.cpp
        src/utils/Utils.h
        src/characters/character.cpp
        src/characters/character.h
        src/characters/mauler.cpp
        src/characters/mauler.h
        src/game_options/options.cpp
        src/game_options/options.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} )
