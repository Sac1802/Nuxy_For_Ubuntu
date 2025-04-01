//
// Created by sac1802 on 4/1/25.
//

#include "WallpaperSetter.h"
#include <cstdlib>
#include <iostream>

bool WallpaperSetter::endWith(const std::string &str, const std::string &suffix) {
    if (str.size() < suffix.size()) return false;
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

std::string WallpaperSetter::getWallpaperDirectory() {
    const char* user = std::getenv("USER");
    return (user) ? std::string("/home/") + user + "/wallpapers": "";
}

std::vector<std::string> WallpaperSetter::getWallpapers() {
    return this->image;
}

void WallpaperSetter::searchWallpapers() {
    std::string wallpaperDir = getWallpaperDirectory();
    for (const auto& entry : fs::directory_iterator(wallpaperDir)) {
        if (entry.is_regular_file()) {
            std::string fileName = entry.path().string();
            if (endWith(fileName, ".jpg") || endWith(fileName, ".jpeg")
                || endWith(fileName, ".png")) {
                this->image.push_back(fileName);
            }
        }
    }
}

void enableBackgroundDrawing() {
    // Comando para habilitar el renderizado de fondo en GNOME
    std::string command = "gsettings set org.gnome.desktop.background draw-background true";

    // Ejecutar el comando y verificar si tuvo éxito
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Error: No se pudo habilitar el dibujo del fondo de pantalla." << std::endl;
    } else {
        std::cout << "Renderizado del fondo de pantalla habilitado correctamente." << std::endl;
    }
}

void WallpaperSetter::setWallpaper(const std::string& imagePath) {
    std::string command = "gsettings set org.gnome.desktop.background picture-uri 'file://" + imagePath + "'";
        int result = system(command.c_str());
}



