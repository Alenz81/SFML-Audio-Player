//
// Created by super on 12/7/2023.
//

#ifndef SFML_AUDIO_PLAYER_TIMEBAR_H
#define SFML_AUDIO_PLAYER_TIMEBAR_H

#include "SFML/Graphics.hpp"
#include "GUIComponent.h"
#include "FontHelper.h"

class TimeBar : public GUIComponent {
private:
    sf::RectangleShape progress;
    sf::RectangleShape border;
    sf::Clock secondTimer;
    bool isUpdating;
    float changeInPixels;
    float totalSeconds;
    float currentPitch;

    float intTimeElapsed, intTimeRemaining;
    sf::Text timeElapsed, timeRemaining;

public:
    TimeBar();

    void setUpdating(bool status);
    bool getUpdating();
    float getChangeInPixels();
    void setTotalSeconds(float seconds, float pitch);
    void moveProgressByOne();

    void makeIntTimeToString();
    int makeStringToInt();
    void resetBar();
    void setElapsedTime(float seconds);
    void songComplete();
    void seeking(float seconds);


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void updateForThread();


    void setPosition(sf::Vector2f pos) override;
    void setSize(sf::Vector2f size) override;

    sf::Vector2f getSizeOfTimeBorder();
    sf::Vector2f getPosOfTimeBorder();
    sf::FloatRect getGlobalBounds() const override;

    Snapshot &getSnapShot() override;
    void applySnapShot(const Snapshot &snapshot) override;

};

#endif //SFML_AUDIO_PLAYER_TIMEBAR_H
