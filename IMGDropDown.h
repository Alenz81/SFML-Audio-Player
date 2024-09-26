//
// Created by super on 11/30/2023.
//

#ifndef SFML_AUDIO_PLAYER_IMGDROPDOWN_H
#define SFML_AUDIO_PLAYER_IMGDROPDOWN_H

#include "DropDown.h"

class IMGDropDown : public DropDown, public States {
public:
    IMGDropDown();
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
};


#endif //SFML_AUDIO_PLAYER_IMGDROPDOWN_H
