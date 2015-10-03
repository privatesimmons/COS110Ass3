cmake_minimum_required(VERSION 3.2)
project(COS_110_ass_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Creature.cpp
    Creature.h
    Dungeon.cpp
    Dungeon.h
    main.cpp
    RandomNumberGenerator.cpp
    RandomNumberGenerator.h
    RolePlayingGame.cpp
    RolePlayingGame.h)

add_executable(COS_110_ass_3 ${SOURCE_FILES})