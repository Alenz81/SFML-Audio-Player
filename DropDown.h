//
// Created by super on 11/9/2023.
//

#ifndef SFML_Audio_Player_DROPDOWN_H
#define SFML_Audio_Player_DROPDOWN_H

#include <vector>
#include "DropDownBox.h"
#include "History.h"


class DropDown : public GUIComponent {
protected:
    std::vector<DropDownBox> boxes;
    sf::Vector2f position;
    bool isSwapping;
    int lastClicked;


public:
    DropDown();
    DropDown(std::vector<std::string> boxTitles);

    void setSwapping(bool isSwap);
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    std::vector<std::string> getStrings();
    int getLastClickedBox();
    std::string getStringOfBox(int index);

    sf::FloatRect getGlobalBounds() const;

    DropDownBox& getTop();
    void addBox(const std::string& string);
    void switchBox(int index1, int index2);
    void hideAllBoxes();

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Snapshot &getSnapShot() override;
    void applySnapShot(const Snapshot &snapshot) override;
};


#endif //DROPDOWN_DROPDOWN_H
