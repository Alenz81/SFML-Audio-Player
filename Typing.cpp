//
// Created by super on 10/14/2023.
//

#include "Typing.h"

Typing::Typing() : isSkip(false), isValidNoSkip(false){
    setFont(FontHelper::getFont());

    setFillColor(sf::Color::Black);
    setCharacterSize(50);
}

void Typing::setString(std::string string) {
    clear();
    for (int i = 0; i < string.size(); i++){
        push_back(string.at(i));
        keyWordColorChange();
        if (std::isdigit(string.at(i))) {
            end().setFillColor(sf::Color::Red);
        } else if (string.at(i) == '+' || string.at(i) == '-' || string.at(i) == '/' || string.at(i) == '*' || string.at(i) == '='){
            end().setFillColor(sf::Color::Green);
        }
    }
}

std::string Typing::getString() {
    std::string string;
    for (int i = 0; i < size(); i++){
        string += at(i).getString();
    }
    return string;
}

bool Typing::getIsSkip() {
    return isSkip;
}

void Typing::setIsSkip(bool isSkip) {
    this->isSkip = isSkip;
}

bool Typing::getIsValidNoSkip() const {
    return isValidNoSkip;
}

void Typing::setIsValidNoSkip(bool status) {
    isValidNoSkip = status;
}

std::string Typing::getEnteredString() {
    return enteredString;
}

std::string Typing::getTypedString() {
    return getString();
}

void Typing::keyWordColorChange() {
    std::string temp;
    int index = size() - 1;
    while ((at(index).getString() != " " || index == 0 ) && index >= 0) {
        temp.insert(0, at(index).getString());
        index--;
    }

    if (temp == "int" || temp == "float" || temp == "char" || temp == "double") {
        paintColor(temp.size(), size(), sf::Color::Blue);
    } else {
        stripColorFromLastWord(sf::Color::Blue, sf::Color::Black);
    }
}

void Typing::paintColor(int size, int index, sf::Color color) {
    for (int i = index; i >= index - size; i--){
        at(i).setFillColor(color);
    }
}

void Typing::stripColorFromLastWord(sf::Color targetColor, sf::Color endColor) {
    int index = size() - 1;
    while ((at(index).getString() != " " || index == 0 ) && index >= 0){
        if (at(index).getFillColor() == targetColor){
            at(index).setFillColor(endColor);
        }
        index--;
    }
}

bool Typing::isValidSkip() {
    std::string string = getString();

    if (stringIsOnlyNum(string)){
        return true;
    }

    //std::cout << "Aftetr only num ";

    if (!doesStringContainNonNumAndColon(string)){
        //std::cout << "doesstring ";
        while (!string.empty()){
            //std::cout << "not empty ";
            std::string stringNums = findLastNumbersAfterColon(string);
            //std::cout << "\nString Nums " << stringNums << "\n";
            //std::cout << stringNums.size();
            if (stringNums.find(':') != std::string::npos && stringNums.size() > 1){
                //std::cout << " : found ";
                if (stringIsOnlyNum(stringNums.substr(1))){
                    int num = std::stoi(stringNums.substr(1));
                    if (num >= 60) {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                if (stringIsOnlyNum(stringNums)){
                    int num = std::stoi(stringNums);
                    if (num >= 60) {
                        return false;
                    }
                }
            }
        }
    } else {
        return false;
    }

    return isFormattingCorrect(getString());

}

bool Typing::stringIsOnlyNum(const std::string& string) {
    for (auto c : string){
        if (!std::isdigit(c)){
            return false;
        }
    }
    return true;
}

bool Typing::doesStringContainNonNumAndColon(const std::string &string) {
    for (int i = 0; i < string.size(); i++){
        if (!std::isdigit(string.at(i)) && string.at(i) != ':'){
            //std::cout << "\n" << string.at(i) << " is a letter\n";
            return true;
        }
    }
    return false;
}

bool Typing::isStringColonAndNoNum(const std::string &string) {
    if (string.find(':') == std::string::npos){
        return false;
    } else {
        for (int i = 0; i < string.size(); i++){
            if (std::isdigit(string.at(i))){
                return false;
            }
        }
    }

    return true;
}

bool Typing::isFormattingCorrect(const std::string &string) {
    //std::cout << "." << string << ".\n";

    if (string.front() == ':' || string.back() == ':'){
        return false;
    }

    if (string.find("::") != std::string::npos){
        return false;
    }

    return true;
}

std::string Typing::findLastNumbersAfterColon(std::string &string) {
    if (string.rfind(':') != std::string::npos && string.size() > 1){
        int posOfColon = string.rfind(':');


        std::string returnString;

        //std::cout << string << " ";

        returnString = string.substr(posOfColon);

        //std::cout << string << " ";
        string = string.substr(0, posOfColon);
        //std::cout << string << " ";

       // std::cout << returnString << "\n";

        return returnString;
    }

    std::string temp = string;
    string = "";
    //std::cout << "find last ";
    return temp;
}

void Typing::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
            pop_back();
            keyWordColorChange();

        } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                if (isValidSkip()){
                    enteredString = getString();
                    isSkip = true;
                }
                clear();
            } else {
                push_back(event.text.unicode);
                keyWordColorChange();
                if (size() != 0) {
                    std::string temp = end().getString();
                    if (std::isdigit(temp.at(0))) {
                        end().setFillColor(sf::Color::Red);
                    } else if (temp == "+" || temp == "-" || temp == "/" || temp == "*" || temp == "=") {
                        end().setFillColor(sf::Color::Green);
                    }
                }
            }



        }
    }

    if (getString().empty()){
        isValidNoSkip = false;
    } else {
        isValidNoSkip = isValidSkip();
    }
}

void Typing::update() {


}


void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    MultiText::draw(window, states);
}

