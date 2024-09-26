//
// Created by super on 11/30/2023.
//

#ifndef SFML_AUDIO_PLAYER_SOUNDBAR_H
#define SFML_AUDIO_PLAYER_SOUNDBAR_H

#include "MenuBar.h"

class SoundBar : public MenuBar, public States {
public:
    SoundBar();
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
};


#endif //SFML_AUDIO_PLAYER_SOUNDBAR_H
