//
// Created by super on 11/3/2023.
//

#ifndef PROJECT_1_TEXTBOX_H
#define PROJECT_1_TEXTBOX_H

#include "GUIComponent.h"
#include "Typing.h"
#include "Box.h"
#include "Engine.h"
#include "Cursor.h"
#include "SnapshotInterface.h"
#include "History.h"

class TextBox : public GUIComponent {
private:
    Typing typing;
    Box box;
    Cursor cursor;
    sf::RectangleShape leftMask;
    sf::Text label;

public:
    TextBox();

    void changeTextVisibility();
    void setPosition(sf::Vector2f pos) override;

    void setSize(sf::Vector2f size) override;

    sf::FloatRect getGlobalBounds() const override;
    float getOutlineThickness();

    bool getIsSkip();
    void setIsSkip(bool isSkip);

    bool getIsValidNoSkip() const;
    void setIsValidNoSkip(bool status);

    std::string getEnteredString();
    std::string getTypedString();

    void clear();

    void setSize(sf::Vector2f size, bool scaleText);
    void setCharSize(float size);

    void setLabel(std::string string);
    std::string getLabel();

    Snapshot &getSnapShot() override;

    void applySnapShot(const Snapshot &snapshot) override;

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PROJECT_1_TEXTBOX_H
