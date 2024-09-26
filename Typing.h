//
// Created by super on 10/14/2023.
//

#ifndef SFML_Audio_Player_TYPING_H
#define SFML_Audio_Player_TYPING_H
#include "GUIComponent.h"
#include <vector>
#include "MultiText.h"
#include "TimeBar.h"

class Typing : public MultiText{
private:

    sf::Font font;
    bool isSkip, isValidNoSkip;
    std::string enteredString;
    std::vector<std::string> keyWords {"int", "char", "double", "float"};

    void keyWordColorChange();
    void paintColor(int size, int index, sf::Color color);
    void stripColorFromLastWord(sf::Color targetColor, sf::Color endColor);

    bool isValidSkip();
    bool stringIsOnlyNum(const std::string& string);
    bool doesStringContainNonNumAndColon(const std::string& string);
    bool isStringColonAndNoNum(const std::string &string);
    bool isFormattingCorrect(const std::string &string);
    std::string findLastNumbersAfterColon(std::string& string);

public:
    Typing();

    void setString(std::string string);
    std::string getString();

    bool getIsSkip();
    void setIsSkip(bool isSkip);

    bool getIsValidNoSkip() const;
    void setIsValidNoSkip(bool status);

    std::string getEnteredString();
    std::string getTypedString();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //SFML_Audio_Player_TYPING_H
