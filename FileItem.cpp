//
// Created by super on 11/20/2023.
//

#include "FileItem.h"

FileItem::FileItem() {
    setIcon(Engine::getTexture());
    changeIcon(0);
    setSize({300, 50});
}

FileItem::FileItem(sf::Texture& image, std::string text, sf::Vector2f size, sf::Vector2f pos) : Item(text) {

    setIcon(image);
    changeIcon(0);
    setPosition(pos);
    setSize(size);

}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    Item::eventHandler(window, event);

}

sf::FloatRect FileItem::getGlobalBounds() const {
    return Item::getGlobalBounds();
}


void FileItem::setPosition(sf::Vector2f pos) {
    Item::setPosition(pos);
    icon.setPosition({pos.x + padding/2, pos.y + padding/2});
    //text.move({(icon.getGlobalBounds().left + icon.getGlobalBounds().width) - this->text.getGlobalBounds().left + padding, 0});
    text.setPosition(icon.getGlobalBounds().left + icon.getGlobalBounds().width + (padding + text.getGlobalBounds().width)/2, text.getGlobalBounds().top + (text.getGlobalBounds().height)/2);
}

void FileItem::setSize(sf::Vector2f size) {
    Item::setSize(size);

    scaleIcon();

    //text.move({(icon.getGlobalBounds().left + icon.getGlobalBounds().width) - this->text.getGlobalBounds().left + padding, 0});
    //text.setPosition(icon.getGlobalBounds().left + icon.getGlobalBounds().width + (padding + text.getGlobalBounds().width)/2, text.getGlobalBounds().top + (text.getGlobalBounds().height)/2);
}

sf::Vector2f FileItem::getPos() {
    return {getGlobalBounds().left, getGlobalBounds().top};
}

sf::Vector2f FileItem::getBottomLeftPos() {
    return {getGlobalBounds().left /*+ getBorderThickness()*/, getGlobalBounds().top + getGlobalBounds().height /*+ getBorderThickness()*/};
}



void FileItem::setIcon(sf::Texture& image) {
    icon.setTexture(image);
}

void FileItem::changeIcon(int image) {
    if (image == 0){
        icon.setTextureRect({0, 0, 352, 452});
    } else if (image == 1){
        icon.setTextureRect({352, 0, 452, 323});
    }

    scaleIcon();
}

void FileItem::scaleIcon() {
    sf::Vector2f scale = {(getSize().y - padding * 1.f)/icon.getGlobalBounds().height, (getSize().y - padding * 1.f)/icon.getGlobalBounds().height};
    icon.scale(scale);
    text.setPosition(icon.getGlobalBounds().left + icon.getGlobalBounds().width + (padding + text.getGlobalBounds().width)/2, text.getGlobalBounds().top + (text.getGlobalBounds().height)/2);
}
