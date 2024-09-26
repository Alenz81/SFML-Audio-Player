//
// Created by super on 10/18/2023.
//

#include "Letter.h"

Letter::Letter() {
    setCharacterSize(24);
    setFillColor(sf::Color::White);
    setFont(FontHelper::getFont());
}

Letter::Letter(char letter) {
    setCharacterSize(24);
    setFillColor(sf::Color::White);
    setFont(FontHelper::getFont());
    setString(letter);
}

Letter::Letter(char letter, sf::Color color, sf::Font font, float size) : defaultFont(font) {
    setCharacterSize(size);
    setFillColor(color);
    setFont(defaultFont);

    setString(letter);
}
