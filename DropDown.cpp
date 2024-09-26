//
// Created by super on 11/9/2023.
//

#include "DropDown.h"

DropDown::DropDown() : position({20, 20}), isSwapping(true), lastClicked(-1) {
    //addBox("File");
    //addBox("Edit");
    //addBox("View");
    //addBox("Bomb");
    //hideAllBoxes();

}

DropDown::DropDown(std::vector<std::string> boxTitles) : isSwapping(true), lastClicked(-1) {
    for (int i = 0; i < boxTitles.size(); i++){
        addBox(boxTitles.at(i));
    }
    hideAllBoxes();
}

void DropDown::setSwapping(bool isSwap) {
    isSwapping = isSwap;
}

void DropDown::setPosition(sf::Vector2f pos) {
    position = pos;
    boxes.front().setPosition(position);

    for (int i = 1; i < boxes.size(); i++){
        boxes.at(i).setPosition({boxes.at(i - 1).getGlobalBounds().left /*+ boxes.at(i - 1).getBorderThickness()*/, boxes.at(i - 1).getGlobalBounds().top + boxes.at(i - 1).getGlobalBounds().height});
    }
}

void DropDown::setSize(sf::Vector2f size) {
    for (DropDownBox &box : boxes){
        box.setSize(size);
    }
    setPosition(position);
}

std::vector<std::string> DropDown::getStrings() {
    std::vector<std::string> temp;
    for (int i = 0; i < boxes.size(); i++){
        temp.push_back(boxes.at(i).getString());
    }
    return temp;
}

int DropDown::getLastClickedBox() {
    return lastClicked;
}

std::string DropDown::getStringOfBox(int index) {
    return boxes.at(index).getString();
}

sf::FloatRect DropDown::getGlobalBounds() const {
    sf::FloatRect temp = boxes.at(0).getGlobalBounds();
    if (boxes.front().checkState(CLICKED)) {
        temp.height *= boxes.size();
    }
    temp.top += boxes.at(0).getBorderThickness();
    temp.width += boxes.at(0).getBorderThickness();
    return temp;
}

DropDownBox &DropDown::getTop() {
    return boxes.front();
}

void DropDown::addBox(const std::string& string) {
    boxes.push_back(*new DropDownBox(string));
    boxes.back().setString(string);

    if (boxes.size() == 1){
        boxes.front().setPosition({100, 100});
        boxes.at(0).setBorder(3, sf::Color::Black);
    } else {
        boxes.back().setPosition({boxes.at(boxes.size() - 2).getGlobalBounds().left /*+ boxes.at(boxes.size()-2).getBorderThickness()*/, boxes.at(boxes.size() - 2).getGlobalBounds().top + boxes.at(boxes.size() - 2).getGlobalBounds().height});
    }

}

void DropDown::switchBox(int index1, int index2) {
    std::string temp = boxes.at(index1).getString();
    boxes.at(index1).setString(boxes.at(index2).getString());
    boxes.at(index2).setString(temp);

    boxes.at(index1).centerText();
    boxes.at(index2).centerText();
}

void DropDown::hideAllBoxes() {
    for (int i = 1; i < boxes.size(); i++){
        boxes.at(i).enableState(HIDDEN);
        boxes.at(i).disableState(CLICKED);
    }
    boxes.at(0).disableState(CLICKED);
}

void DropDown::eventHandler(sf::RenderWindow &window, sf::Event event) {

    for (DropDownBox &box : boxes){
        if (!box.checkState(HIDDEN)) {
            box.eventHandler(window, event);
        }
    }

    if (boxes.front().checkState(CLICKED) && !boxes.at(1).checkState(HIDDEN)){
        if (boxes.front().getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            hideAllBoxes();
        }

    }

    if (boxes.front().checkState(CLICKED)){
        lastClicked = 0;
        for (DropDownBox &box : boxes){
            box.disableState(HIDDEN);
        }
    }



    for (int i = 1; i < boxes.size(); i++){
        if (boxes.at(i).checkState(CLICKED)){
            lastClicked = i;

            HistoryNode historyNode;

            historyNode.snapshot = getSnapShot();
            historyNode.component = static_cast<GUIComponent*>(this);

            History::pushHistory(historyNode);

            if(isSwapping){
                switchBox(0, i);
            }

            hideAllBoxes();
            break;
        }
    }
    if (!boxes.front().checkState(CLICKED)){
        hideAllBoxes();
    }



    if (!getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
        hideAllBoxes();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //lastClicked = -1;
        }
    }


}

void DropDown::update() {
    for (DropDownBox &box : boxes){
        if (!box.checkState(HIDDEN)) {
            box.update();
        }
    }


}

void DropDown::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const DropDownBox &box : boxes){
        if (!box.checkState(HIDDEN)) {
            target.draw(box);
        }
    }
}

Snapshot &DropDown::getSnapShot() {
    Snapshot *snapshot = new Snapshot;

    for (int i = 0; i < boxes.size(); i++){
        snapshot->pushStringData(boxes.at(i).getString());
    }
    return *snapshot;
}

void DropDown::applySnapShot(const Snapshot &snapshot) {
    for (int i = 0; i < snapshot.stringDatas.size(); i++){
        boxes.at(i).setString(snapshot.stringDatas.at(i));
    }
    setPosition(position);
}
