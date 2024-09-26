//
// Created by super on 11/20/2023.
//

#ifndef FILE_TREE_FILETREE_H
#define FILE_TREE_FILETREE_H

#include "FileNode.h"


class FileTree : public GUIComponent{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode* parent, FileNode* child); //FileNode*& root, std::string parent, std::string item
    FileNode* find(FileNode* parent, std::string data);
    FileNode* createNode(const std::string &data);
    bool pathMissingRoot(std::string path);
    void addRootToPath(std::string &path);
    void fillMissingDirectories(FileNode *&p, std::string &path, std::string fullPath);
    std::string getNextInPath(std::string &path);
    //traverses the tree ad adds the evenhandlers for each of the nodes
    //void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};
public:
    //constructors
    FileTree();

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos) override;


    //this is the public version of push
    void push(std::string path); //std::string parent, std::string item = "NULL"

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now

    //calls the traverse function to add the event handlers to each node
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;

    Snapshot &getSnapShot() override;

    void applySnapShot(const Snapshot &snapshot) override;

    //does nothing now
    void update();
    //does nothing now

    //does nothing now
    sf::FloatRect getGlobalBounds() const override;
};


#endif //FILE_TREE_FILETREE_H
