cmake_minimum_required(VERSION 3.30)
project(NuxyVerUbuntu)

set(CMAKE_CXX_STANDARD 20)

add_executable(NuxyVerUbuntu main.cpp
        App/App.cpp
        App/App.h
        wallpaper_setter/WallpaperSetter.cpp
        wallpaper_setter/WallpaperSetter.h)
