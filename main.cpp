#include <iostream>
#include "Application.h"
#include "SongAndManipulations.h"
#include "FileTree.h"
#include "MenuBar.h"
#include "Button.h"
#include "TimeBar.h"
#include "TextBox.h"

int main() {
    /*
    FileNode node(Engine::getTexture(), "mommy", {200, 50}, {10, 10});

    FileNode node1(Engine::getTexture(), "aa", {200, 50}, {10, 10});

    node1.addChildren(new FileNode(Engine::getTexture(), "bb", {600, 100}, {100, 300}));
    node1.addChildren(new FileNode(Engine::getTexture(), "cc", {600, 100}, {100, 300}));
    node1.addChildren(new FileNode(Engine::getTexture(), "dd", {600, 100}, {100, 300}));


    node.addChildren(new FileNode(Engine::getTexture(), "Destroy", {600, 100}, {100, 300}));
    node.addChildren(&node1);
    node.addChildren(new FileNode(Engine::getTexture(), "Build", {600, 100}, {100, 300}));

    node.addChildren(new FileNode(Engine::getTexture(), "Destroy", {600, 100}, {100, 300}));



    Application::addComponent(node);*/
/*
    FileTree tree;

    tree.push("Directory 1");

    tree.push("Directory 1/Directory 2");

    tree.push("Directory 1/Directory 2/Directory 4/File 1");
    tree.push("Directory 1/Directory 2/File 1");
    tree.push("Directory 1/Directory 2/File 2");
    tree.push("Directory 1/Directory 2/File 3");
    tree.push("Directory 1/Directory 2/File 4");
    tree.push("Directory 1/Directory 2/File 5");

    tree.push("Directory 1/Directory 3/File 1");

    //tree.setPosOfRoot({20, 20});
    //tree.setSizeOfRoot({250, 75});

    Application::addComponent(tree);*/
/*
    MenuBar menu;
    menu.addDropDown({"Pitch", "-5", "0", "+5"});
    menu.addDropDown({"Volume", "-5", "0", "+5"});
    menu.addDropDown({"Location", "Back Left", "Back Right", "Front Left", "Front Right", "Center"});

    MenuBar menu2;
    menu2.addDropDown({"Pitch", "-5", "0", "+5"});
    menu2.addDropDown({"Volume", "-5", "0", "+5"});
    menu2.addDropDown({"Location", "Back Left", "Back Right", "Front Left", "Front Right", "Center"});

    DropDownBox box;

    menu.setPosition({200, 200});

    //Application::addComponent(menu);
    //Application::addComponent(menu2);
*/



    //std::u32string s[]{U"\uE101"};
    //std::wstring temp = L"\uE100 \uE101 \uE102";

    //Button button(L"\uE100 \uE102 \uE101");

    //Application::addComponent(button);

    SongAndManipulations song;
    Application::addComponent(song);
/*
    TimeBar timeBar;
    timeBar.setUpdating(true);
    timeBar.setTotalSeconds(100);
    timeBar.setPosition({200, 200});
    Application::addComponent(timeBar);
*/
/*
    TextBox textBox2;
    textBox2.setLabel("Last Name");
    textBox2.setPosition({300, 300});
    textBox2.setSize({200, 50}, true);
    Application::addComponent(textBox2);
*/

    Application::run();

    return 0;
}
