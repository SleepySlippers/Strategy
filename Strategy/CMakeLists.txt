cmake_minimum_required(VERSION 3.15)
project(MyStrategy)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyStrategy main.cpp Colorize.h AbstractUnits/Unit.h Properties/Movable.h Properties/PhysicalObject.h Properties/Hittable.h AbstractUnits/Warrior.h AbstractUnits/Swordsman.h MyUtilite.h Properties/Handleable.h Map.h MainHandler.h Properties/Named.h AbstractUnits/Horseman.h AbstractUnits/Archer.h AbstractUnits/Building.h AbstractUnits/TownHall.h Factory/Spawner.h AbstractUnits/Worker.h Factory/FranceFactory.h Factory/EnglandFactory.h AbstractUnits/Barracks.h Drawer.h ColoredString.h Groups/InSquadWarrior.h AbstractUnits/InSquadUnit.h Groups/Group.h Groups/Squad.h AbstractUnits/PhysicalSquad.h AbstractUnits/SquadSwordsman.h Factory/MyFactory.h Factory/EnemyFactory.h)