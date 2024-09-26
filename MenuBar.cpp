//
// Created by super on 11/14/2023.
//

#include "MenuBar.h"

MenuBar::MenuBar() : position({20, 20}), lastClicked({-1, -1}){

}

sf::FloatRect MenuBar::getGlobalBounds() const {
    sf::FloatRect temp = dropdowns.at(0).getGlobalBounds();
    temp.width *= dropdowns.size();

    return temp;
}

sf::Vector2i MenuBar::getClicked() {
    return lastClicked;

}

void MenuBar::setPosition(sf::Vector2f pos) {
    position = pos;
    for (int i = 0; i < dropdowns.size(); i++){
        dropdowns.at(i).setPosition({pos.x + i * dropdowns.at(i).getGlobalBounds().width, pos.y});
    }

}

void MenuBar::setSize(sf::Vector2f size) {
    size.x = size.x/dropdowns.size();
    size.y = size.y/dropdowns.size();

    for (int i = 0; i < dropdowns.size(); i++){
        dropdowns.at(i).setSize(size);
    }
    setPosition(position);
}

void MenuBar::addDropDown(std::vector<std::string> boxTitles) {
    dropdowns.emplace_back(boxTitles);
    dropdowns.back().setSwapping(false);
    if (dropdowns.size() > 1){
        int max(dropdowns.size() - 1);
        dropdowns.at(max).setPosition({dropdowns.at(max - 1).getGlobalBounds().left + dropdowns.at(max - 1).getGlobalBounds().width,
                dropdowns.at(max - 1).getGlobalBounds().top});
    } else {
        dropdowns.at(0).setPosition(position);
    }
}

void MenuBar::eventHandler(sf::RenderWindow &window, sf::Event event) {
    int dropDownClicked(lastClicked.x), boxClicked(lastClicked.y);
    if (isSomethingSelected()){
        for (int i = 0; i < dropdowns.size(); i++){
            if (i == findHovered()){
                dropdowns.at(i).eventHandler(window, event);
                dropDownClicked = i;
                boxClicked = dropdowns.at(i).getLastClickedBox();
            } else {
                dropdowns.at(i).hideAllBoxes();
            }
        }
    } else {
        for (int i = 0; i < dropdowns.size(); i++){
            dropdowns.at(i).eventHandler(window, event);
            if (i == dropDownClicked){
                boxClicked = dropdowns.at(i).getLastClickedBox();
            }
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        lastClicked = {dropDownClicked, boxClicked};
    }

}

void MenuBar::update() {
    for (DropDown &dropDown : dropdowns){
        dropDown.update();
    }
}

Snapshot &MenuBar::getSnapShot() {
    Snapshot snapshot;
    return snapshot;

}

void MenuBar::applySnapShot(const Snapshot &snapshot) {

}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const DropDown& dropDown : dropdowns){
        target.draw(dropDown);
    }
}

bool MenuBar::isSomethingSelected() {
    for (auto box : dropdowns){
        if (box.getTop().checkState(HOVERED)){
            return true;
        }
    }
    return false;
}

int MenuBar::findHovered() {
    for (int i = 0; i < dropdowns.size(); i++){
        if (dropdowns.at(i).getTop().checkState(HOVERED)){
            return i;
        }
    }
    return -1;
}
