//
// Created by super on 11/9/2023.
//

#include "DropDownBox.h"

DropDownBox::DropDownBox() {
    rect.setFillColor({193, 193, 191});
    text.setFont(Engine::getFont());
    text.setFillColor(sf::Color::Black);
}

DropDownBox::DropDownBox(const std::string& string) : DropDownBox() {
    text.setString(string);
}



void DropDownBox::setString(const std::string& string) {
    text.setString(string);
}

std::string DropDownBox::getString() {
    return text.getString();
}

void DropDownBox::centerText() {
    Engine::centerText(rect, text);
}

void DropDownBox::setBorder(float size, const sf::Color &color) {
    rect.setOutlineThickness(size);
    rect.setOutlineColor(color);
}

float DropDownBox::getBorderThickness() const {
    return rect.getOutlineThickness();
}

void DropDownBox::eventHandler(sf::RenderWindow &window, sf::Event event) {
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

void DropDownBox::update() {
    if (checkState(HOVERED)){
        //rect.setFillColor(sf::Color::Blue);
        text.setFillColor(sf::Color::White);
    } else {
        //rect.setFillColor({213, 213, 211});
        text.setFillColor(sf::Color::Black);
    }
}

void DropDownBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Box::draw(window, states);
    window.draw(text);
}

void DropDownBox::setSize(sf::Vector2f size) {
    Box::setSize(size);
    text.setCharacterSize(getGlobalBounds().height/2);
    Engine::centerText(rect, text);

}

void DropDownBox::setPosition(sf::Vector2f pos) {
    Box::setPosition(pos);
    Engine::centerText(rect, text);
    //text.setPosition({getGlobalBounds().left - 10 - getGlobalBounds().width, getGlobalBounds().top + getGlobalBounds().height/2.f - text.getGlobalBounds().height});
}

sf::FloatRect DropDownBox::getGlobalBounds() const {
    sf::FloatRect temp;
    temp.top = rect.getPosition().y;
    temp.left = rect.getPosition().x;
    temp.width = rect.getSize().x;
    temp.height = rect.getSize().y;
    return temp;
}

