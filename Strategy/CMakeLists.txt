cmake_minimum_required(VERSION 3.15)
project(MyStrategy)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyStrategy main.cpp Colorize.h Unit.h Movable.h PhysicalObject.h Hittable.h Warrior.h Swordmen.h MyUtilite.h Handleable.h Map.h MainHandler.h Named.h)