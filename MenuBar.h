//
// Created by super on 11/14/2023.
//

#ifndef MENU_BAR_MENUBAR_H
#define MENU_BAR_MENUBAR_H

#include "DropDown.h"

class MenuBar : public GUIComponent{
protected:
    std::vector<DropDown> dropdowns;
    sf::Vector2f position;
    sf::Vector2i lastClicked;

public:
    MenuBar();
    sf::FloatRect getGlobalBounds() const;

    sf::Vector2i getClicked();
    void setPosition(sf::Vector2f pos) override;
    void setSize(sf::Vector2f size);
    void addDropDown(std::vector<std::string> boxTitles);
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool isSomethingSelected();
    int findHovered();

    Snapshot &getSnapShot() override;
    void applySnapShot(const Snapshot &snapshot) override;


};


#endif //MENU_BAR_MENUBAR_H
