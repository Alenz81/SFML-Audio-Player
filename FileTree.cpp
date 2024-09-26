//
// Created by super on 11/20/2023.
//

#include "FileTree.h"

void FileTree::push(FileNode *parent, FileNode *child) {
    //std::cout << "Adding " << child->getFileItem().getString() << " to " << parent->getFileItem().getString() << std::endl;
    for (FileNode* t : parent->getChildren()){
        if (t->getFileItem().getString() == child->getFileItem().getString()){
            return;
        }
    }
    parent->addChildren(child);
}

FileNode *FileTree::find(FileNode *parent, std::string data) {
    if (parent){
        //std::cout << parent->getChildren().size() << "  Size\n";
        for (FileNode* t : parent->getChildren()){
            //std::cout << "child " << t->getFileItem().getString() << " find " << data << std::endl;
            if (t->getFileItem().getString() == data){
                //std::cout << "TRUE\n";
                return t;
            }
        }
    }
    return nullptr;
}

FileNode *FileTree::createNode(const std::string &data) {
    FileNode* t = new FileNode;
    t->getFileItem().setString(data);
    t->initialize();
    return t;
}

void FileTree::fillMissingDirectories(FileNode*& p, std::string &path, std::string fullPath) {
    std::string otherDirectories = fullPath.substr(0, fullPath.find(path));
    while (!path.empty()){
        std::string directory;
        if (!otherDirectories.empty()){
            directory = getNextInPath(otherDirectories);
        } else {
            directory = getNextInPath(path);
            push(p, createNode(directory));
            p->getFileItem().changeIcon(1);
            p = find(p, directory);

        }
    }
}

std::string FileTree::getNextInPath(std::string &path) {
    if (path.find('/') != std::string::npos){
        int idx = path.find('/');
        std::string s = path.substr(0,idx);
        path = path.substr(idx + 1);
        return s;
    } else {
        std::string temp = path;
        path = "";
        return temp;
    }
}

FileTree::FileTree() {

}

void FileTree::setSize(sf::Vector2f size) {
    root->setSize(size);
}

void FileTree::setPosition(sf::Vector2f pos) {
    root->setPosition(pos);
}

void FileTree::push(std::string path) {
    if (!root){
        std::string directory = getNextInPath(path);
        root = createNode(directory);
        root->getFileItem().setBorder(3, sf::Color::Black);
    }

    if (pathMissingRoot(path)){
        addRootToPath(path);
    }

    std::string fullPath = path;
    FileNode* parent = root;
    while(!path.empty()){
        std::string directory = getNextInPath(path);
        if (root->getFileItem().getString() == directory){
            //getNextInPath(path);
        }
        //std::cout << "parent " << parent->getFileItem().getString() << " directory " << directory << std::endl;
        FileNode* found = find(parent, directory);
        //std::cout << "found " << found->getFileItem().getString() << std::endl;
        if (!found){
            fillMissingDirectories(parent, path, fullPath);
            //std::cout << "drector\n";
        }
        parent = found;
    }
}

bool FileTree::pathMissingRoot(std::string path) {
    std::string directory = getNextInPath(path);
    return directory != root->getFileItem().getString();
}

void FileTree::addRootToPath(std::string &path) {
    path.insert(0, root->getFileItem().getString() + "/");
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}

void FileTree::update() {
    root->update();
}


void FileTree::eventHandler(sf::RenderWindow &window, sf::Event event) {
    root->eventHandler(window, event);
}

Snapshot &FileTree::getSnapShot() {
    Snapshot snapshot;
    return snapshot;
}

void FileTree::applySnapShot(const Snapshot &snapshot) {

}

sf::FloatRect FileTree::getGlobalBounds() const {
    return root->getGlobalBounds();
}
