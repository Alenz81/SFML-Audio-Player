//
// Created by super on 10/18/2023.
//

#include "MultiText.h"

MultiText::MultiText() : color(sf::Color::White), pos({0, 0}), font(FontHelper::getFont()){}

void MultiText::setFillColor(sf::Color color) {
    this->color = color;
    for (Letter& letter : list){
        letter.setFillColor(color);
    }
}

void MultiText::setCharacterSize(int size) {
    charSize = size;
    for (Letter letter : list){
        letter.setCharacterSize(size);
    }
}

float MultiText::getEndCharSpacing() {
    sf::Glyph glyph = font.getGlyph(list.back().getString()[0], charSize, false);
    return glyph.advance;
}

float MultiText::getCharacterSize() {
    return charSize;
}

void MultiText::setFont(sf::Font font) {
    this->font = font;
    for (Letter letter : list){
        letter.setFont(font);
    }
}

void MultiText::push_back(char letter) {
    float width(0);

    sf::Glyph glyph;

    if (!list.empty()){
        glyph = font.getGlyph(list.back().getString()[0], charSize, false);
        width = (list.back().getGlobalBounds().left + glyph.advance);
    }

    list.emplace_back(*new Letter(letter, color, font, charSize));
    list.back().setPosition(width + pos.x, pos.y);

}

void MultiText::pop_back() {
    if (list.size() > 0) {
        list.pop_back();
    }
}

void MultiText::setPosition(const sf::Vector2f& pos) {
    float xPos(0);
    for (Letter &letter : list){
        letter.setPosition(pos.x + xPos, pos.y);
        sf::Glyph glyph = font.getGlyph(letter.getString()[0], charSize, false);
        xPos += glyph.advance;
    }
}

int MultiText::size() {
    return list.size();

}

sf::FloatRect MultiText::getGlobalBounds() const {
    sf::FloatRect floatRect;
    if (!list.empty()) {
        floatRect.top = list.front().getGlobalBounds().top;
        floatRect.left = list.front().getGlobalBounds().left;
        floatRect.width = (list.back().getGlobalBounds().left + list.back().getGlobalBounds().width) - list.front().getGlobalBounds().left;
        floatRect.height = list.front().getGlobalBounds().height;
    }
    return floatRect;
}


Letter& MultiText::begin() {
    return list.front();
}

Letter& MultiText::end() {
    return list.back();
}

Letter &MultiText::at(int index) {
    int temp(0);
    for (Letter &letter : list){
        if (temp == index){
            return letter;
        }
        temp++;
    }

    Letter* letter = new Letter;
    letter->setString("-1");
    return *letter;
}

void MultiText::clear() {
    while (!list.empty()){
        pop_back();
    }
}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (Letter letter : list){
        if (!letter.checkState(HIDDEN)){
            target.draw(letter);
        }
    }
}
