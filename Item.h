//
// Created by super on 11/9/2023.
//

#ifndef DROPDOWN_DROPDOWNBOX_H
#define DROPDOWN_DROPDOWNBOX_H

#include "Box.h"
#include "States.h"
#include "Engine.h"


class Item : public Box  {
protected:
    sf::Text text;

public:
    Item();
    Item(const std::string& string);

    void setString(const std::string& string);
    std::string getString();

    void centerText();

    void setBorder(float size, const sf::Color& color);
    float getBorderThickness() const;

    void setSize(const sf::Vector2f &size);
    sf::Vector2f getSize() const;
    void setPosition(const sf::Vector2f &pos);

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //DROPDOWN_DROPDOWNBOX_H
