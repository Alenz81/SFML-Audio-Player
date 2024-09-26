//
// Created by super on 12/2/2023.
//

#include "Button.h"

Button::Button() : Item() {
    text.setFont(Engine::getButtonFont());
    setBorder(3, sf::Color::Black);
    setSize({50, 50});
}

Button::Button(sf::String string) : Button() {
    text.setString(string);
}

void Button::setString(sf::String string) {
    text.setString(string);
    centerText();
}

sf::String Button::getString() {
    return text.getString();
}

void Button::setPosition(sf::Vector2f pos) {
    Item::setPosition(pos);
}

void Button::setSize(sf::Vector2f size) {
    Item::setSize(size);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    Item::eventHandler(window, event);
    if (getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)){
        enableState(CLICKED);
    }
}

sf::FloatRect Button::getGlobalBounds() const {
    return Item::getGlobalBounds();
}


