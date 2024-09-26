//
// Created by super on 11/30/2023.
//

#include "IMGDropDown.h"


IMGDropDown::IMGDropDown() : DropDown() {
    addBox("Nickelback");
    addBox("Apple");
    addBox("Dave");
}

void IMGDropDown::eventHandler(sf::RenderWindow &window, sf::Event event) {
    int temp = lastClicked;
    DropDown::eventHandler(window, event);
    if (lastClicked != temp && lastClicked > 0){ //will use file extensions, like for loop
        enableState(CLICKED);

    }




}
