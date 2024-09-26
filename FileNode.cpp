//
// Created by super on 11/20/2023.
//

#include "FileNode.h"
#include "SongAndManipulations.h"

void FileNode::toggleChlidren() {

}

FileNode::FileNode() {

}

FileNode::FileNode(sf::Texture& image, std::string text, sf::Vector2f size, sf::Vector2f position) : FileNode(){
    data = FileItem(image, text, size, position);
}

void FileNode::addChildren(FileNode *node) {
    data.changeIcon(1);
    children.push_back(node);
    node->parent = this;
    consolidateChildren();

}

void FileNode::initialize() {
    setSize(data.getSize());
    setPosition(data.getPos());
}

void FileNode::setSize(sf::Vector2f size) {
    data.setSize(size);
}

sf::Vector2f FileNode::getSize() {
    return data.getSize();
}

void FileNode::setPosition(sf::Vector2f pos) {
    data.setPosition(pos);
}

sf::Vector2f FileNode::getPos() {
    return data.getPos();
}

sf::Vector2f FileNode::getBottomLeftPos() {
    return data.getBottomLeftPos();
}

FileItem& FileNode::getFileItem() {
    return data;
}

void FileNode::consolidateChildren() {
    for (FileNode*& i : children){
        i->setSize(data.getSize());
    }

    reEvaluatePos();

    for (int i = 0; i < children.size(); i++){
        if (!children.at(i)->isLeaf()){
            children.at(i)->consolidateChildren();
        }
    }
}

void FileNode::reEvaluatePos() {
    sf::Vector2f offSetPos = data.getBottomLeftPos();
    offSetPos.x += indentOffset;
    if (!children.empty()) {
        children.at(0)->setPosition(offSetPos);

        for (int i = 1; i < children.size(); i++) {
            children.at(i)->setPosition(
                    {children.at(i - 1)->getGlobalBounds().left,
                     children.at(i - 1)->getGlobalBounds().top + children.at(i - 1)->getGlobalBounds().height});
        }
    }

    /*
    for (int i = 1; i < children.size(); i++){
        children.at(i)->setPosition(children.at(i-1)->getBottomLeftPos());
    }*/
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(data);
    if (checkState(CLICKED)){
        for (int i = 0; i < children.size(); i++){
            window.draw(*children.at(i));
        }
    }

}

void FileNode::eventHandler(sf::RenderWindow &window, sf::Event event) {
    data.eventHandler(window, event);

    if (data.checkState(CLICKED) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        toggleState(CLICKED);
    }

    if(checkState(CLICKED)){

        if (isLeaf()){

        } else {
            for (int i = 0; i < children.size(); i++) {
                children.at(i)->eventHandler(window, event);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            consolidateChildren();
        }

        if (isLeaf()){
            openFile();
            disableState(CLICKED);
        }
    }


}

void FileNode::openFile() {
    std::string directory;

    FileNode* walker = this;

    while(walker){
        directory.insert(0, "/" + walker->getFileItem().getString());
        walker = walker->parent;
    }

    directory = directory.substr(1);

    SongAndManipulations::loadSong(directory);

}

void FileNode::update() {
    data.update();
    if(checkState(CLICKED)){
        for (int i = 0; i < children.size(); i++){
            children.at(i)->update();
        }
    }
}

sf::FloatRect FileNode::getGlobalBounds() const {
    /*sf::FloatRect rect = data.getGlobalBounds();
    if (!checkState(HIDDEN)){
        rect.height += children.size() * data.getGlobalBounds().height;
        rect.width += indentOffset;
    }
    return rect;*/

    sf::FloatRect rect = data.getGlobalBounds();
    //rect.left -= data.getBorderThickness();
    //rect.top -= data.getBorderThickness();
    if (!checkState(HIDDEN)){
        sf::Vector2f size;
        getBounds(size);

        rect.height = size.y;
        rect.width = size.x;
    }
    return rect;
}

void FileNode::getBounds(sf::Vector2f &size) const {
    int x(0), y(0), temp(0);
    size += data.getSize();

    findXExposed(temp, x);
    size.x += indentOffset * x;

    findYExposed(y);
    size.y += data.getSize().y * y;

}

void FileNode::findXExposed(int &temp, int &x) const {
    if (checkState(CLICKED)){
        if (!children.empty()){
            temp++;
            if (x < temp){
                x = temp;
                temp = 0;
            }
            for (int i = 0; i < children.size(); i++){
                children.at(i)->findXExposed(temp, x);
            }
        } else {
            temp = 0;
        }
    }
}

void FileNode::findYExposed(int &y) const {
    if (checkState(CLICKED)){
        if (!children.empty()){
            y += children.size();
            for (int i = 0; i < children.size(); i++){
                children.at(i)->findYExposed(y);
            }
        }
    }
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode *> &FileNode::getChildren() {
    return children;
}

Snapshot &FileNode::getSnapShot() {
    Snapshot snapshot;
    return snapshot;
}

void FileNode::applySnapShot(const Snapshot &snapshot) {

}
