//
// Created by super on 12/7/2023.
//

#include "TimeBar.h"


TimeBar::TimeBar() : isUpdating(false), progress({0, 50}), border({1000, 50}), intTimeElapsed(0), intTimeRemaining(0) {
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Black);
    border.setOutlineThickness(5);
    progress.setFillColor(sf::Color::Green);

    timeElapsed.setFont(FontHelper::getFont());
    timeRemaining.setFont(FontHelper::getFont());

    makeIntTimeToString();
    //timeElapsed.setString("0:00");
    //timeRemaining.setString("0:00");

    timeElapsed.setCharacterSize(border.getSize().y);
    timeRemaining.setCharacterSize(border.getSize().y);

    timeElapsed.setFillColor(sf::Color::Black);
    timeRemaining.setFillColor(sf::Color::Black);

    setPosition(timeElapsed.getPosition());
}

void TimeBar::setUpdating(bool status) {
    isUpdating = status;
    secondTimer.restart();
}

bool TimeBar::getUpdating() {
    return isUpdating;
}

float TimeBar::getChangeInPixels() {
    changeInPixels = border.getSize().x/totalSeconds;
    return changeInPixels;
}

void TimeBar::setTotalSeconds(float seconds, float pitch) {
    float changeInPitch = pitch - currentPitch + 1;
    currentPitch = pitch;

    if (pitch > 1){
        pitch = (1 - (pitch - 1));
    } else if (pitch < 1) {
        pitch = (1 + (1 - pitch));
    }

    seconds *= pitch;

    totalSeconds = seconds;
    intTimeRemaining = totalSeconds - intTimeElapsed;


    progress.setSize({intTimeElapsed * getChangeInPixels(), progress.getSize().y});


    makeIntTimeToString();
    getChangeInPixels();
}

void TimeBar::moveProgressByOne() {
    if (intTimeRemaining - 1 > 0){
        intTimeElapsed++;
        intTimeRemaining--;
        progress.setSize({progress.getSize().x + changeInPixels, progress.getSize().y});
    } else {
        songComplete();
    }

    if (progress.getSize().x >= border.getSize().x){
        songComplete();
    }


    makeIntTimeToString();

}

void TimeBar::makeIntTimeToString() {
    int tempElapsed = intTimeElapsed;
    int tempRemain = intTimeRemaining;

    std::string temp;

    temp += std::to_string(tempElapsed / 60);
    temp += ":";
    tempElapsed -= (tempElapsed / 60 * 60);
    if (tempElapsed < 10){
        temp += std::to_string(0);
    }
    temp += std::to_string(tempElapsed);



    timeElapsed.setString(temp);

    temp = "";

    temp += std::to_string(tempRemain / 60);
    temp += ":";
    tempRemain -= (tempRemain / 60 * 60);
    if (tempRemain < 10){
        temp += std::to_string(0);
    }
    temp += std::to_string(tempRemain);


    timeRemaining.setString(temp);

}

int TimeBar::makeStringToInt() {
    return 0;
}

void TimeBar::resetBar() {
    intTimeElapsed = 0;
    intTimeRemaining = totalSeconds;
    makeIntTimeToString();
    progress.setSize({0, progress.getSize().y});
}

void TimeBar::setElapsedTime(float seconds) {
    intTimeElapsed = seconds;
    intTimeRemaining = totalSeconds - intTimeElapsed;
    progress.setSize({intTimeElapsed * getChangeInPixels(), progress.getSize().y});
    makeIntTimeToString();
}

void TimeBar::songComplete() {
    intTimeElapsed = totalSeconds;
    intTimeRemaining = 0;
    progress.setSize(border.getSize());
    makeIntTimeToString();
}

void TimeBar::seeking(float seconds) {
    if (seconds + intTimeElapsed < 0){
        intTimeElapsed = 0;
        intTimeRemaining = totalSeconds;
        isUpdating = false;
        progress.setSize({0, progress.getSize().y});
    } else if (seconds + intTimeElapsed > totalSeconds) {
        intTimeElapsed = totalSeconds;
        intTimeRemaining = 0;
        isUpdating = false;
        progress.setSize({totalSeconds * getChangeInPixels(), progress.getSize().y});
    } else {
        intTimeElapsed += seconds;
        intTimeRemaining -= seconds;
        progress.setSize({intTimeElapsed * getChangeInPixels(), progress.getSize().y});
    }
    makeIntTimeToString();
}


void TimeBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(border);
    target.draw(progress);
    target.draw(timeRemaining);
    target.draw(timeElapsed);
}

void TimeBar::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TimeBar::update() {
    if (intTimeRemaining < 1) {
        songComplete();
    }
}

void TimeBar::updateForThread() {

    while (isUpdating) {
        if (secondTimer.getElapsedTime().asSeconds() >= 0.99999999){
            secondTimer.restart();
            //progress.setSize({progress.getSize().x + changeInPixels, progress.getSize().y});
            intTimeElapsed++;
            intTimeRemaining--;
            progress.setSize({intTimeElapsed * changeInPixels, progress.getSize().y});
            makeIntTimeToString();

        }

        if (intTimeElapsed >= totalSeconds){
            isUpdating = false;
            progress.setSize(border.getSize());
        }
    }
}

void TimeBar::setPosition(sf::Vector2f pos) {

    /*
    border.setPosition(pos);
    progress.setPosition(pos);

    timeElapsed.setPosition({border.getGlobalBounds().left - border.getOutlineThickness() - timeElapsed.getGlobalBounds().width - 10, border.getGlobalBounds().top + border.getOutlineThickness()/2 - border.getGlobalBounds().height/2 + timeElapsed.getCharacterSize()/2});
    timeRemaining.setPosition({border.getGlobalBounds().left + border.getGlobalBounds().width + 10, border.getGlobalBounds().top + border.getOutlineThickness()/2 - border.getGlobalBounds().height/2 + timeElapsed.getCharacterSize()/2});
     */

    timeElapsed.setPosition(pos);

    border.setPosition({timeElapsed.getGlobalBounds().left + timeElapsed.getGlobalBounds().width + 10, timeElapsed.getGlobalBounds().top + timeElapsed.getGlobalBounds().height/2 - border.getGlobalBounds().height/2 + border.getOutlineThickness()});
    progress.setPosition(border.getPosition());

    timeRemaining.setPosition({border.getGlobalBounds().left + border.getGlobalBounds().width + 10 - border.getOutlineThickness(), border.getGlobalBounds().top + border.getOutlineThickness() - border.getGlobalBounds().height/2 + timeElapsed.getCharacterSize()/2});

}

void TimeBar::setSize(sf::Vector2f size) {
    border.setSize(size);

    getChangeInPixels();

    progress.setSize({progress.getSize().x, size.y});

    timeElapsed.setCharacterSize(size.y);
    timeRemaining.setCharacterSize(size.y);

    setPosition(timeElapsed.getPosition());
}

sf::Vector2f TimeBar::getSizeOfTimeBorder() {
    return border.getSize();
}

sf::Vector2f TimeBar::getPosOfTimeBorder() {
    return border.getPosition();
}

sf::FloatRect TimeBar::getGlobalBounds() const {
    sf::FloatRect temp = border.getGlobalBounds();

    temp.left = timeElapsed.getGlobalBounds().left;
    temp.width = timeRemaining.getGlobalBounds().left + timeRemaining.getGlobalBounds().width - timeElapsed.getGlobalBounds().left;

    return temp;
}

Snapshot &TimeBar::getSnapShot() {
    Snapshot snapshot;
    return snapshot;
}

void TimeBar::applySnapShot(const Snapshot &snapshot) {

}
