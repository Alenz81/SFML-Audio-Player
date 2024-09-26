//
// Created by super on 11/9/2023.
//

#ifndef SFML_Audio_Player_DROPDOWNBOX_H
#define SFML_Audio_Player_DROPDOWNBOX_H

#include "Box.h"
#include "Engine.h"


class DropDownBox : public Box  {
private:
    sf::Text text;

public:
    DropDownBox();
    DropDownBox(const std::string& string);

    void setString(const std::string& string);
    std::string getString();

    void centerText();

    void setBorder(float size, const sf::Color& color);
    float getBorderThickness() const;

    void setSize(sf::Vector2f size) override;
    void setPosition(sf::Vector2f pos) override;

    sf::FloatRect getGlobalBounds() const override;


    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //SFML_Audio_Player_DROPDOWNBOX_H
