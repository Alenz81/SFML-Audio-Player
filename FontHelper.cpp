//
// Created by super on 12/8/2023.
//

#ifndef SFML_AUDIO_PLAYER_FONTHELPER_CPP
#define SFML_AUDIO_PLAYER_FONTHELPER_CPP

#include "FontHelper.h"


sf::Font &FontHelper::getFont() {
    if (!isFontLoaded){
        isFontLoaded = font.loadFromFile("Fonts/times.ttf");
    }
    return font;
}

#endif