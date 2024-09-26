//
// Created by super on 10/18/2023.
//

#ifndef SFML_Audio_Player_LETTER_H
#define SFML_Audio_Player_LETTER_H
#include <SFML/Graphics.hpp>
#include "FontHelper.h"
#include "States.h"

class Letter : public sf::Text, public States {
private:
    sf::Font defaultFont;
public:
    Letter();
    Letter(char letter);
    Letter(char letter, sf::Color color, sf::Font font, float size);
};


#endif //SFML_Audio_Player_LETTER_H
