//
// Created by super on 10/31/2023.
//

#ifndef STATES_EXANOKE_BOX_H
#define STATES_EXANOKE_BOX_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "States.h"

class Box : public GUIComponent, public States {
protected:
    sf::RectangleShape rect;
public:
    Box();
    Box(const sf::Vector2f &size);


    virtual void setSize(sf::Vector2f size);

    virtual void setPosition(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds() const;
    float getOutLineThickness();
    void setOutlineThickness(float thickness);
    void setOutlineColor(sf::Color color);

    Snapshot &getSnapShot() override;

    void applySnapShot(const Snapshot &snapshot) override;

    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //STATES_EXANOKE_BOX_H
