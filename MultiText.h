//
// Created by super on 10/18/2023.
//

#ifndef SFML_Audio_Player_MULTITEXT_H
#define SFML_Audio_Player_MULTITEXT_H
#include <list>
#include "Letter.h"

class MultiText : public sf::Drawable {
private:
    std::list<Letter> list;
    float charSize;
    sf::Color color;
    sf::Font font;
    sf::Vector2f pos;

public:
    MultiText();
    void setFillColor(sf::Color color);
    void setCharacterSize(int size);
    float getCharacterSize();
    float getEndCharSpacing();
    void setFont(sf::Font font);
    void push_back(char letter);
    void pop_back();
    void setPosition(const sf::Vector2f& pos);
    int size();
    sf::FloatRect getGlobalBounds() const;
    Letter& begin();
    Letter& end();
    Letter& at(int index);
    void clear();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_Audio_Player_MULTITEXT_H
