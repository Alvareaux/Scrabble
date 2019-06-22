cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scrabble main.cpp
        lib/additional_func.cpp lib/additional_func.h
        lib/misc_func.h lib/misc_func.cpp
        lib/game_func.cpp lib/game_func.h
        dictionary/dictionary.cpp dictionary/dictionary.h)

add_executable(Helper helper.cpp
        lib/additional_func.cpp lib/additional_func.h
        lib/misc_func.h lib/misc_func.cpp
        lib/game_func.cpp lib/game_func.h
        dictionary/dictionary.cpp dictionary/dictionary.h)