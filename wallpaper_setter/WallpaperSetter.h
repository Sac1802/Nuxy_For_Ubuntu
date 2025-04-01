//
// Created by sac1802 on 4/1/25.
//

#ifndef WALLPAPERSETTER_H
#define WALLPAPERSETTER_H
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class WallpaperSetter {
private:
    std::vector<std::string> image;
public:
    bool endWith(const std::string& str, const std::string& suffix);
    std::string getWallpaperDirectory();
    std::vector<std::string> getWallpapers();

    void searchWallpapers();
    void setWallpaper(const std::string& imagesPath);
};



#endif //WALLPAPERSETTER_H
