//
// Created by super on 11/30/2023.
//

#include "SoundBar.h"

SoundBar::SoundBar() {
    addDropDown({"Pitch", "-5", "0", "+5"});
    addDropDown({"Volume", "-10", "0", "+10"});
    addDropDown({"Location", "Back Left", "Back Right", "Front Left", "Front Right", "Center"});
}

void SoundBar::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2i temp = getClicked();
    MenuBar::eventHandler(window, event);

    //std::cout << "x " << getClicked().x << " y " << getClicked().y << std::endl;
    //std::cout << "x " << temp.x << " y " << temp.y << std::endl;

    if (getClicked() != temp && getClicked().y > 0) {
        enableState(CLICKED);
        //std::cout << "x " << getClicked().x << " y " << getClicked().y << std::endl;
        //std::cout << "x " << temp.x << " y " << temp.y << std::endl;

    }





}
