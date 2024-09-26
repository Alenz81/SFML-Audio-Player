//
// Created by super on 11/3/2023.
//

#include "Cursor.h"

Cursor::Cursor() {
    enableState(HIDDEN);
    rect.setSize({3, 50});
    rect.setFillColor(sf::Color::Black);
}

void Cursor::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
}

void Cursor::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

sf::FloatRect Cursor::getGlobalBounds() const {
    return rect.getGlobalBounds();
}

void Cursor::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Cursor::update() {
    if (Engine::getClockSeconds() > 0.5 && !checkState(HIDDEN)){
        toggleState(BLINKING);
        Engine::resetClock();
    }
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!checkState(HIDDEN) && checkState(BLINKING)){
        target.draw(rect);
    }
}

Snapshot &Cursor::getSnapShot() {
    Snapshot snapshot;

    return snapshot;
}

void Cursor::applySnapShot(const Snapshot &snapshot) {

}
