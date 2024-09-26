//
// Created by super on 11/3/2023.
//

#ifndef SFML_Audio_Player_ENGINE_CPP
#define SFML_Audio_Player_ENGINE_CPP

#include "Engine.h"

//sf::Font Engine::font;
//sf::Clock Engine::clock;
//bool Engine::loadedFont = false;

void Engine::loadFont() {
    if (!loadedFont) {
        loadedFont = font.loadFromFile("Fonts/times.ttf");
    }
}

void Engine::loadButtonFont() {
    if (!loadedButtonFont) {
        loadedButtonFont = buttonFont.loadFromFile("Fonts/seguisym.ttf");
    }
}

void Engine::loadTexture() {
    if (!loadedTexture){
        loadedTexture = texture.loadFromFile("Images/document&folder v2.png");
    }
}

void Engine::loadBGTexture() {
    if (!loadedBGTexture){
        loadedBGTexture = backGroundTexture.loadFromFile("Images/background v1.png");
    }
}

sf::Font &Engine::getFont() {
    loadFont();
    return font;
}

sf::Font &Engine::getButtonFont() {
    loadButtonFont();
    return buttonFont;
}

sf::Texture &Engine::getTexture() {
    loadTexture();
    return texture;
}

sf::Texture &Engine::getBGTexture() {
    loadBGTexture();
    return backGroundTexture;
}


double Engine::getClockSeconds() {
    return clock.getElapsedTime().asSeconds();
}

void Engine::resetClock() {
    clock.restart();
}

sf::VideoMode Engine::getWorkingWindowSize() {

    sf::VideoMode temp = sf::VideoMode::getDesktopMode();
    temp.height *= 0.9;
    temp.width *= 0.9;

    //temp = {1440, 1080};
    return temp;
}

template<typename T>
void Engine::centerText(const T &obj, sf::Text &text) {
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

template<typename T>
void Engine::leftText(const T &obj, Typing &text) {
    text.setPosition({obj.getGlobalBounds().left + 10, obj.getGlobalBounds().top + obj.getGlobalBounds().height/2.f - text.getCharacterSize()/1.6f});
}

template<typename T>
void Engine::rightText(const T &obj, Typing &text) {
    text.setPosition({obj.getGlobalBounds().left + obj.getGlobalBounds().width - text.getGlobalBounds().width - 15, obj.getGlobalBounds().top + obj.getGlobalBounds().height/2.f - text.getCharacterSize()/1.6f});
}

#endif