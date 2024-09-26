//
// Created by super on 11/20/2023.
//

#ifndef FILE_TREE_FILEITEM_H
#define FILE_TREE_FILEITEM_H

#include "Item.h"
#include <SFML/Graphics.hpp>

class FileItem : public Item {
private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 20;
public:
    //Constructors
    FileItem();
    FileItem(sf::Texture &image, std::string text, sf::Vector2f size, sf::Vector2f pos);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    void setPosition(sf::Vector2f pos) override;
    sf::Vector2f getPos();
    void setSize(sf::Vector2f size);

    sf::Vector2f getBottomLeftPos();
    //uses an enum to change the icon to a folder or file
    void setIcon(sf::Texture& image);

    void changeIcon(int image);

    void scaleIcon();


};


#endif //FILE_TREE_FILEITEM_H
