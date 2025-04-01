//
// Created by sac1802 on 4/1/25.
//

#include "App.h"

#include <iostream>
#include <thread>

#include "../wallpaper_setter/WallpaperSetter.h"

void App::run() {

    WallpaperSetter wallpaperSetter;
    std::cout << "init app" << std::endl;
    wallpaperSetter.searchWallpapers();

    while (true) {
        if (!wallpaperSetter.getWallpapers().empty()) {
            static size_t index = 0;
            wallpaperSetter.setWallpaper(wallpaperSetter.getWallpapers()[index]);
            index = (index + 1) % wallpaperSetter.getWallpapers().size();
        }
        std::this_thread::sleep_for(std::chrono::seconds(5 * 10));
    }
}

