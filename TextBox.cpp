//
// Created by super on 11/3/2023.
//

#include "TextBox.h"

TextBox::TextBox() {
    box.setSize({200, 100});
    box.setPosition({(720 - box.getGlobalBounds().width)/2.f, (480 - box.getGlobalBounds().height)/2.f});
    box.setOutlineThickness(5);
    box.setOutlineColor(sf::Color::Black);
    leftMask.setFillColor(sf::Color::White);
    leftMask.setSize({5, 100});
    leftMask.setPosition({box.getGlobalBounds().left + 5, box.getGlobalBounds().top + 5});
    cursor.setPosition({box.getGlobalBounds().left + typing.getGlobalBounds().width, box.getGlobalBounds().top/2.f + cursor.getGlobalBounds().height/2.f});
    label.setFont(Engine::getFont());
    label.setFillColor(sf::Color::Black);

}

void TextBox::setPosition(sf::Vector2f pos) {
    label.setPosition({pos.x, pos.y - label.getGlobalBounds().height/2 + box.getGlobalBounds().height/2 - box.getOutLineThickness()});
    box.setPosition({label.getGlobalBounds().left + label.getGlobalBounds().width + 10, label.getGlobalBounds().top + label.getGlobalBounds().height/2 - box.getGlobalBounds().height/2 + box.getOutLineThickness()/2});


    cursor.setPosition({box.getGlobalBounds().left + typing.getGlobalBounds().width, box.getGlobalBounds().top/2.f + cursor.getGlobalBounds().height/2.f});
    leftMask.setPosition({box.getGlobalBounds().left + 5, box.getGlobalBounds().top + 5});

    /*
    box.setPosition(pos);
    leftMask.setPosition({box.getGlobalBounds().left + 5, box.getGlobalBounds().top + 5});
    cursor.setPosition({box.getGlobalBounds().left + typing.getGlobalBounds().width, box.getGlobalBounds().top/2.f + cursor.getGlobalBounds().height/2.f});
    label.setPosition({box.getGlobalBounds().left - 10 - label.getGlobalBounds().width, box.getGlobalBounds().top + box.getGlobalBounds().height/2.f - label.getGlobalBounds().height});
*/
}

void TextBox::setSize(sf::Vector2f size, bool scaleText) {
    box.setSize(size);
    leftMask.setSize({leftMask.getGlobalBounds().width, box.getGlobalBounds().height - box.getOutLineThickness() * 2});
    cursor.setSize({cursor.getGlobalBounds().width, size.y/2});
    label.setCharacterSize(box.getGlobalBounds().height/2);
    label.setPosition({box.getGlobalBounds().left - 10 - label.getGlobalBounds().width, box.getGlobalBounds().top + box.getGlobalBounds().height/2.f - label.getGlobalBounds().height});
    if (scaleText){
        setCharSize(box.getGlobalBounds().height/2);
    }
}

void TextBox::setCharSize(float size) {
    typing.setCharacterSize(size);
}

void TextBox::setLabel(std::string string) {
    label.setString(string);
    label.setCharacterSize(box.getGlobalBounds().height/2);
    label.setPosition({box.getGlobalBounds().left - 10 - label.getGlobalBounds().width, box.getGlobalBounds().top + box.getGlobalBounds().height/2.f - label.getGlobalBounds().height - box.getOutLineThickness()/2});
}

std::string TextBox::getLabel() {
    return label.getString();
}


void TextBox::changeTextVisibility() {
    for (int i = 0; i < typing.size(); i++){
        if (typing.at(i).getGlobalBounds().left - 1 <= box.getGlobalBounds().left){
            typing.at(i).enableState(HIDDEN);
        } else {
            typing.at(i).disableState(HIDDEN);
        }
    }
}

void TextBox::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace) && typing.size() > 0){
        HistoryNode historyNode;

        historyNode.snapshot = getSnapShot();

        historyNode.component = static_cast<GUIComponent*>(this);
        History::pushHistory(historyNode);
    }
    box.eventHandler(window, event);
    if (box.checkState(CLICKED)) {
        cursor.disableState(HIDDEN);
        typing.eventHandler(window, event);
        cursor.eventHandler(window, event);
    } else {
        cursor.enableState(HIDDEN);
    }


}

void TextBox::update() {
    box.update();
    typing.update();
    if (typing.getGlobalBounds().width < box.getGlobalBounds().width - 15){
        Engine::leftText(box, typing);
    } else {
        Engine::rightText(box, typing);
    }
    changeTextVisibility();
    if (typing.size() != 0){
        cursor.setPosition({typing.getGlobalBounds().left + typing.getGlobalBounds().width + 2,
                            box.getGlobalBounds().top + box.getGlobalBounds().height / 2.f -
                            cursor.getGlobalBounds().height / 2.f});
    } else {
        cursor.setPosition({box.getGlobalBounds().left + typing.getGlobalBounds().width + 10, box.getGlobalBounds().top + box.getGlobalBounds().height / 2.f - cursor.getGlobalBounds().height / 2.f});
    }
    cursor.update();
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(typing);
    target.draw(leftMask);
    target.draw(cursor);
    target.draw(label);
}

Snapshot &TextBox::getSnapShot() {
    Snapshot *snapshot = new Snapshot;
    snapshot->pushStringData(typing.getString());
    for (int i = 0; i < LAST_STATE; i++){
        if (cursor.checkState(static_cast<statesEnum>(i))){
            snapshot->addStateData(static_cast<statesEnum>(i), 0);
        }
    }
    return *snapshot;
}

void TextBox::applySnapShot(const Snapshot &snapshot) {
    if (!snapshot.stateDatas.empty() && !snapshot.stateDatas.at(0).empty()) {
        for (int i = 0; i < snapshot.stateDatas.at(0).size(); i++) {
            cursor.enableState(snapshot.stateDatas.at(0).at(i));
        }
    }
    typing.setString(snapshot.stringDatas.at(0));


}

void TextBox::setSize(sf::Vector2f size) {

}

sf::FloatRect TextBox::getGlobalBounds() const {
    sf::FloatRect temp = box.getGlobalBounds();

    //temp.top = box.getGlobalBounds().top + 50;
    temp.left = label.getGlobalBounds().left;
    temp.width = box.getGlobalBounds().left + box.getGlobalBounds().width - label.getGlobalBounds().left;

    return temp;
}

float TextBox::getOutlineThickness() {
    return box.getOutLineThickness();
}

bool TextBox::getIsSkip() {
    return typing.getIsSkip();
}

void TextBox::setIsSkip(bool isSkip) {
    typing.setIsSkip(isSkip);
}

bool TextBox::getIsValidNoSkip() const {
    return typing.getIsValidNoSkip();
}

void TextBox::setIsValidNoSkip(bool status) {
    typing.setIsValidNoSkip(status);
}

std::string TextBox::getEnteredString() {
    return typing.getEnteredString();
}

std::string TextBox::getTypedString() {
    return typing.getTypedString();
}


void TextBox::clear() {
    typing.clear();
    typing.setIsValidNoSkip(false);
}
