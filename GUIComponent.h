//
// Created by super on 10/31/2023.
//

#ifndef STATES_EXANOKE_GUICOMPONENT_H
#define STATES_EXANOKE_GUICOMPONENT_H

#include "SnapshotInterface.h"
#include <SFML/Graphics.hpp>

class GUIComponent : public sf::Drawable, public SnapshotInterface{
public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;
    virtual void setPosition(sf::Vector2f pos) = 0;
    virtual void setSize(sf::Vector2f size) = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
};


#endif //STATES_EXANOKE_GUICOMPONENT_H
