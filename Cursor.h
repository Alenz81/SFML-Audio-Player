//
// Created by super on 11/3/2023.
//

#ifndef PROJECT_1_CURSOR_H
#define PROJECT_1_CURSOR_H

#include "GUIComponent.h"
#include "States.h"
#include "Engine.h"
#include <iostream>

class Cursor : public GUIComponent, public States{
private:
    sf::RectangleShape rect;
public:
    Cursor();

    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    sf::FloatRect getGlobalBounds() const;



    Snapshot &getSnapShot() override;

    void applySnapShot(const Snapshot &snapshot) override;

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PROJECT_1_CURSOR_H
