//
// Created by super on 12/8/2023.
//

#ifndef SFML_AUDIO_PLAYER_FONTHELPER_H
#define SFML_AUDIO_PLAYER_FONTHELPER_H

#include "SFML/Graphics.hpp"

class FontHelper {
private:
    inline static sf::Font font;
    inline static bool isFontLoaded;

public:
    inline static sf::Font& getFont();
};

#include "FontHelper.cpp"

#endif //SFML_AUDIO_PLAYER_FONTHELPER_H
