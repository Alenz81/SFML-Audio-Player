//
// Created by super on 12/2/2023.
//

#ifndef SFML_AUDIO_PLAYER_BUTTON_H
#define SFML_AUDIO_PLAYER_BUTTON_H

#include "Item.h"

class Button : public Item {
public:
    Button();
    Button(sf::String string);

    void setString(sf::String string);
    sf::String getString();

    void setPosition(sf::Vector2f pos) override;

    void setSize(sf::Vector2f size) override;

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;

    sf::FloatRect getGlobalBounds() const override;
};


#endif //SFML_AUDIO_PLAYER_BUTTON_H
