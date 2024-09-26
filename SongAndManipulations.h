//
// Created by super on 12/1/2023.
//

#ifndef SFML_AUDIO_PLAYER_SONGANDMANIPULATIONS_H
#define SFML_AUDIO_PLAYER_SONGANDMANIPULATIONS_H

#include "FileTree.h"
#include "SoundBar.h"
#include "IMGDropDown.h"
#include "Button.h"
#include "SFML/Audio.hpp"
#include "TimeBar.h"
#include "TextBox.h"

class SongAndManipulations : public GUIComponent{
private:
    FileTree tree;
    SoundBar menu;
    IMGDropDown drop;
    sf::RectangleShape rect, skipRect, potentialBarRect;
    static TimeBar timeBar;
    sf::Thread *thread;

    sf::Sprite backGround;

    Button rewind, togglePlayBack, forward;

    static TextBox textBox;

    static sf::Music songAudio;
    static bool isSongLoaded;

    static std::string songDirectory;
    static float originalPitch;
    static float originalVolume;

    float prevSongTime;

    void menuIsClicked(sf::Vector2i coords);
    void dropIsClicked(int index);

    void sizeBG();

    void songAdvance();
public:
    SongAndManipulations();

    void setPosition(sf::Vector2f windowSize) override;
    void setSize(sf::Vector2f size) override;

    void skipTo(const std::string& string);
    int stringToInt(const std::string& string);
    void calcPosOfSkipRect(const std::string& string);

    static void loadSong(std::string fileName);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;

    sf::FloatRect getGlobalBounds() const override;

    Snapshot &getSnapShot() override;
    void applySnapShot(const Snapshot &snapshot) override;


};


#endif //SFML_AUDIO_PLAYER_SONGANDMANIPULATIONS_H
