//
// Created by super on 11/3/2023.
//

#ifndef SFML_Audio_Player_ENGINE_H
#define SFML_Audio_Player_ENGINE_H

#include "SFML/Graphics.hpp"
#include <cmath>
#include <iostream>
#include "Typing.h"

class Engine {
private:
    inline static sf::Font font;
    inline static bool loadedFont;
    inline static void loadFont();

    inline static sf::Font buttonFont;
    inline static bool loadedButtonFont;
    inline static void loadButtonFont();

    inline static sf::Texture texture;
    inline static bool loadedTexture;
    inline static void loadTexture();

    inline static sf::Texture backGroundTexture;
    inline static bool loadedBGTexture;
    inline static void loadBGTexture();

    inline static sf::Clock clock;

    inline static sf::VideoMode windowSize = sf::VideoMode::getDesktopMode();

public:
    inline static sf::Font& getFont();
    inline static sf::Font& getButtonFont();
    inline static sf::Texture& getTexture();
    inline static sf::Texture& getBGTexture();
    inline static double getClockSeconds();
    inline static void resetClock();
    inline static sf::VideoMode getWorkingWindowSize();

    template<typename T>
    inline static void centerText(const T &obj, sf::Text &text);
    template<typename T>
    inline static void leftText(const T &obj, Typing &text);
    template<typename T>
    inline static void rightText(const T &obj, Typing &text);
};

#include "Engine.cpp"

#endif //SFML_Audio_Player_ENGINE_H
