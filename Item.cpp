//
// Created by super on 11/9/2023.
//

#include "Item.h"

Item::Item() {
    rect.setFillColor({193, 193, 191});
    text.setFont(Engine::getFont());
    text.setFillColor(sf::Color::Black);
}

Item::Item(const std::string& string) : Item() {
    text.setString(string);
}

void Item::setString(const std::string& string) {
    text.setString(string);
}

std::string Item::getString() {
    return text.getString();
}

void Item::centerText() {
    Engine::centerText(rect, text);
}

void Item::setBorder(float size, const sf::Color &color) {
    rect.setOutlineThickness(size);
    rect.setOutlineColor(color);
}

float Item::getBorderThickness() const {
    return rect.getOutlineThickness();
}

void Item::eventHandler(sf::RenderWindow &window, sf::Event event) {
    Box::eventHandler(window, event);

    /*
    if (checkState(CLICKED)){
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if (rect.getGlobalBounds().contains(mpos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                disableState(CLICKED);
            }
        }
    }*/
}

void Item::update() {
    if (checkState(HOVERED)){
        //rect.setFillColor(sf::Color::Blue);
        text.setFillColor(sf::Color::White);
    } else {
        //rect.setFillColor({213, 213, 211});
        text.setFillColor(sf::Color::Black);
    }
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Box::draw(window, states);
    window.draw(text);
}

void Item::setSize(const sf::Vector2f &size) {
    Box::setSize(size);
    text.setCharacterSize(getGlobalBounds().height/2);
    Engine::centerText(rect, text);

}

sf::Vector2f Item::getSize() const {
    return rect.getSize();
}

void Item::setPosition(const sf::Vector2f &pos) {
    Box::setPosition(pos);
    Engine::centerText(rect, text);
    //text.setPosition({getGlobalBounds().left - 10 - getGlobalBounds().width, getGlobalBounds().top + getGlobalBounds().height/2.f - text.getGlobalBounds().height});
}
