//
// Created by super on 11/20/2023.
//

#ifndef FILE_TREE_FILENODE_H
#define FILE_TREE_FILENODE_H

#include "FileItem.h"

class FileNode : public GUIComponent, public States{
private:
    //This is the data represented in the tree
    FileItem data;
    FileNode* parent = nullptr;

    //this is all the child nodes in the tree, a vector would also work just fine
    std::vector<FileNode*> children;

    float indentOffset = 10;

    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void getBounds(sf::Vector2f &size) const;
    void findXExposed(int &temp, int &x) const;
    void findYExposed(int &y) const;
public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;
    FileNode();
    FileNode(sf::Texture& image, std::string text, sf::Vector2f size, sf::Vector2f position);

    void openFile();

    void addChildren(FileNode *node);

    void initialize();

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;


    void consolidateChildren();
    void reEvaluatePos();


    void setSize(sf::Vector2f size);
    sf::Vector2f getSize();
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPos();
    sf::Vector2f getBottomLeftPos();

    FileItem& getFileItem();

    //does nothing now
    virtual void update();
    //does nothing now
    Snapshot &getSnapShot() override;

    void applySnapShot(const Snapshot &snapshot) override; //virtual void???
    //does nothing now
    sf::FloatRect getGlobalBounds() const override;
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode*>& getChildren();

};


#endif //FILE_TREE_FILENODE_H
