//
// Created by super on 10/31/2023.
//

#include "Box.h"

Box::Box() : Box({200, 50}) {
    rect.setOutlineColor(sf::Color::Black);
    //rect.setOutlineThickness(5);
}

Box::Box(const sf::Vector2f &size) : rect(size){
    rect.setOutlineColor(sf::Color::Black);
    //rect.setOutlineThickness(5);
}

void Box::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

void Box::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
}

sf::FloatRect Box::getGlobalBounds() const{
    return rect.getGlobalBounds();
}

float Box::getOutLineThickness() {
    return rect.getOutlineThickness();
}

void Box::setOutlineThickness(float thickness) {
    rect.setOutlineThickness(thickness);
}

void Box::setOutlineColor(sf::Color color) {
    rect.setOutlineColor(color);
}

void Box::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if (!checkState(HIDDEN)) {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if (rect.getGlobalBounds().contains(mpos)) {
            enableState(HOVERED);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type != sf::Event::EventType::MouseMoved) {
                enableState(CLICKED);
                disableState(HOVERED);
            }
        } else {
            disableState(HOVERED);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type != sf::Event::EventType::MouseMoved) {
                disableState(CLICKED);
            }
        }

    }
}

void Box::update() {
    if (checkState(HOVERED)){
        //rect.setFillColor(sf::Color::Yellow);
    } else {
        //rect.setFillColor(sf::Color::White);
    }

    if (checkState(CLICKED)){
        //rect.setFillColor(sf::Color::Blue);
    }

}

void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!checkState(HIDDEN)){
        window.draw(rect);
    }

}

Snapshot &Box::getSnapShot() {
    Snapshot snapshot;

    return snapshot;
}

void Box::applySnapShot(const Snapshot &snapshot) {

}
