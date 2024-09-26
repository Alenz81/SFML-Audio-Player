//
// Created by super on 12/1/2023.
//

#include "SongAndManipulations.h"

TimeBar SongAndManipulations::timeBar;
TextBox SongAndManipulations::textBox;
sf::Music SongAndManipulations::songAudio;
bool SongAndManipulations::isSongLoaded = false;
std::string SongAndManipulations::songDirectory;
float SongAndManipulations::originalPitch = 1;
float SongAndManipulations::originalVolume = 50;

SongAndManipulations::SongAndManipulations() {  
    tree.push("Songs/My Songs/3 am eq v2.wav");
    tree.push("Songs/My Songs/3 am eq v2.5 mono.wav");
    tree.push("Songs/My Songs/snippet.wav");
    tree.push("Songs/Corporate Music/Corporate Soft.mp3");


    sf::Vector2f temp;
    temp.x = Engine::getWorkingWindowSize().width;
    temp.y = Engine::getWorkingWindowSize().height;

    Button button(L"\uE100 \uE102 \uE101");

    rewind.setString(L"\uE100");
    togglePlayBack.setString(L"\uE102");
    forward.setString(L"\uE101");


    backGround.setTexture(Engine::getBGTexture());
    backGround.setTextureRect({0, 0, 1080, 1080});

    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(5);
    rect.setOutlineColor(sf::Color::Black);

    skipRect.setOutlineThickness(5);
    skipRect.setOutlineColor(sf::Color::Black);

    textBox.setLabel("Skip To: ");

    potentialBarRect.setFillColor(sf::Color::Black);




    setPosition(temp);

    //thread = new sf::Thread(&TimeBar::updateForThread, &timeBar);
    thread = new sf::Thread(&SongAndManipulations::songAdvance, this);
    thread->launch();

    //sf::Thread thread(&TimeBar::updateForThread, &timeBar);
    //thread.launch();

}

void SongAndManipulations::menuIsClicked(sf::Vector2i coords) {
    if (coords.x == 0) {
        if (coords.y == 1) {
            songAudio.setPitch(songAudio.getPitch() - 0.05);
        } else if (coords.y == 2) {
            songAudio.setPitch(originalPitch);
        } else if (coords.y == 3) {
            songAudio.setPitch(songAudio.getPitch() + 0.05);
        }

    } else if (coords.x == 1) {
        if (coords.y == 1) {
            songAudio.setVolume(songAudio.getVolume() - 20);
        } else if (coords.y == 2) {
            songAudio.setVolume(originalVolume);
        } else if (coords.y == 3) {
            songAudio.setVolume(songAudio.getVolume() + 20);
        }
    } else if (coords.x == 2) {
        float location(0.1);
        if (coords.y == 1) {
            songAudio.setPosition({-1 * location, -1 * location, 0});
        } else if (coords.y == 2) {
            songAudio.setPosition({location, -1 * location, 0});
        } else if (coords.y == 3) {
            songAudio.setPosition({-1 * location, location, 0});
        } else if (coords.y == 4) {
            songAudio.setPosition({location, location, 0});
        } else if (coords.y == 5) {
            songAudio.setPosition({0, 0, 0});
        }
    }
}

void SongAndManipulations::songAdvance() {
    while(songAudio.getStatus() == sf::SoundSource::Playing){
        if (songAudio.getPlayingOffset().asSeconds() - prevSongTime >= 1){
            timeBar.moveProgressByOne();
            prevSongTime++;
        }
    }
}

void SongAndManipulations::dropIsClicked(int index) {
    std::string temp = drop.getStringOfBox(0);

    if (temp == "Nickelback"){
        backGround.setTextureRect({0, 0, 1080, 1080});
    } else if (temp == "Apple") {
        backGround.setTextureRect({1084, 0, 1307, 1080});
    } else if (temp == "Dave") {
        backGround.setTextureRect({1080 + 1307, 0, 1542, 1080});
    }
    sizeBG();
}

void SongAndManipulations::sizeBG() {
    sf::Vector2f size;
    size.x = Engine::getWorkingWindowSize().width/backGround.getGlobalBounds().width;
    size.y = Engine::getWorkingWindowSize().height/backGround.getGlobalBounds().height;

    backGround.scale(size);


}

void SongAndManipulations::setPosition(sf::Vector2f windowSize) {
    tree.setPosition({20, 20});
    menu.setPosition({windowSize.x/2 - menu.getGlobalBounds().width/2, 20});
    drop.setPosition({windowSize.x - drop.getGlobalBounds().width - 20, 20});

    rect.setSize({windowSize.x / 1.7f, windowSize.y / 7});
    rect.setPosition({windowSize.x/2 - rect.getGlobalBounds().width/2, windowSize.y - rect.getGlobalBounds().height - 10});

    timeBar.setSize({rect.getGlobalBounds().width/1.2f, rect.getGlobalBounds().height/7});
    timeBar.setPosition({rect.getGlobalBounds().left + rect.getGlobalBounds().width/2 - timeBar.getGlobalBounds().width/2, rect.getGlobalBounds().top + timeBar.getGlobalBounds().height * 0.8f});

    sf::Vector2f buttonSize = {rect.getSize().y/3, rect.getSize().y/3};

    forward.setSize(buttonSize);
    togglePlayBack.setSize(buttonSize);
    rewind.setSize(buttonSize);

    sf::Vector2f toggleButtonPos = {rect.getGlobalBounds().left + rect.getGlobalBounds().width/2 - togglePlayBack.getGlobalBounds().width/2, rect.getGlobalBounds().top + rect.getGlobalBounds().height - togglePlayBack.getGlobalBounds().height * 1.3f};

    togglePlayBack.setPosition(toggleButtonPos);
    rewind.setPosition({toggleButtonPos.x - togglePlayBack.getGlobalBounds().width - 10, toggleButtonPos.y});
    forward.setPosition({toggleButtonPos.x + togglePlayBack.getGlobalBounds().width + 10, toggleButtonPos.y});

    skipRect.setSize({rect.getGlobalBounds().width/3, rect.getGlobalBounds().height * 0.6f});
    skipRect.setPosition({rect.getGlobalBounds().left + rect.getGlobalBounds().width/2 - skipRect.getGlobalBounds().width/2, rect.getGlobalBounds().top - skipRect.getGlobalBounds().height - 10});

    textBox.setSize({skipRect.getGlobalBounds().width * 0.35f, skipRect.getGlobalBounds().height * 0.5f}, true);
    textBox.setPosition({skipRect.getGlobalBounds().left + skipRect.getGlobalBounds().width/2 - textBox.getGlobalBounds().width/2, skipRect.getGlobalBounds().top + skipRect.getGlobalBounds().height/2 - textBox.getGlobalBounds().height/2 - textBox.getOutlineThickness()/2});

    potentialBarRect.setSize({2, timeBar.getSizeOfTimeBorder().y});

    sizeBG();
}

void SongAndManipulations::setSize(sf::Vector2f size) {

}

void SongAndManipulations::skipTo(const std::string &string) {
    if (isSongLoaded){
        if (songAudio.getStatus() == sf::SoundSource::Stopped){
            songAudio.play();
        }

        float skipBy = stringToInt(string) - songAudio.getPlayingOffset().asSeconds();

        songAudio.setPlayingOffset(sf::seconds(songAudio.getPlayingOffset().asSeconds() + skipBy));
        if (skipBy > songAudio.getDuration().asSeconds()) {
            timeBar.songComplete();
        } else {
            timeBar.setElapsedTime(songAudio.getPlayingOffset().asSeconds() - 1);
        }
        prevSongTime = songAudio.getPlayingOffset().asSeconds() - 1;
        thread->launch();
    }
}


void SongAndManipulations::calcPosOfSkipRect(const std::string &string) {
    float skipTo = stringToInt(string);
    potentialBarRect.setPosition({timeBar.getPosOfTimeBorder().x + skipTo * timeBar.getChangeInPixels(), timeBar.getPosOfTimeBorder().y});
}

int SongAndManipulations::stringToInt(const std::string &string) {
    if (!string.empty()) {
        if (string.find(':') == std::string::npos) {
            return std::stoi(string);
        }
    }

    int seconds = 0;
    int unitsToSeconds = 0;
    std::string temp = string;

    while (!temp.empty()){
        if (temp.rfind(':') != std::string::npos){
            int index = temp.rfind(':');
            int lastNums = std::stoi(temp.substr(index + 1));
            temp = temp.substr(0, index);

            if (unitsToSeconds == 0){
                seconds += lastNums;
            } else {
                seconds += lastNums * unitsToSeconds * 60;
            }
        } else {
            seconds += std::stoi(temp) * unitsToSeconds * 60;
            temp = "";
        }
        unitsToSeconds++;
    }
    return seconds;
}

void SongAndManipulations::loadSong(std::string fileName) {
    if (fileName != songDirectory){

        if (songAudio.openFromFile(fileName)){
            songAudio.setVolume(originalVolume);
            songAudio.setPitch(originalPitch);
            songAudio.setPosition({0, 0, 0});
            isSongLoaded = true;
            timeBar.setTotalSeconds(songAudio.getDuration().asSeconds(), 1);
            timeBar.resetBar();
            textBox.clear();
        }

    }
    songDirectory = fileName;

}

void SongAndManipulations::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(backGround);

    target.draw(tree);
    target.draw(menu);
    target.draw(drop);

    target.draw(rect);
    target.draw(timeBar);
    target.draw(skipRect);
    target.draw(textBox);

    target.draw(rewind);
    target.draw(togglePlayBack);
    target.draw(forward);

    if (textBox.getIsValidNoSkip()){
        target.draw(potentialBarRect);
    }

}


void SongAndManipulations::eventHandler(sf::RenderWindow &window, sf::Event event) {

    tree.eventHandler(window, event);
    menu.eventHandler(window, event);
    drop.eventHandler(window, event);

    timeBar.eventHandler(window, event);
    textBox.eventHandler(window, event);

    rewind.eventHandler(window, event);
    togglePlayBack.eventHandler(window, event);
    forward.eventHandler(window, event);

    if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))) && event.type != sf::Event::EventType::MouseMoved) {
        if (menu.checkState(CLICKED)) {
            menuIsClicked(menu.getClicked());
            menu.disableState(CLICKED);
        }

        if (drop.checkState(CLICKED)|| (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) && event.type != sf::Event::EventType::MouseMoved) {
            dropIsClicked(drop.getLastClickedBox());
            drop.disableState(CLICKED);
        }

        if (isSongLoaded) {
            if (rewind.checkState(CLICKED)) {
                if (songAudio.getStatus() == sf::SoundSource::Stopped){
                    timeBar.resetBar();
                    prevSongTime = 0;
                    songAudio.play();
                    timeBar.setUpdating(true);
                } else {
                    float seconds = 15;
                    if (songAudio.getPitch() > 1){
                        seconds = seconds * (1 - (songAudio.getPitch() - 1));
                    } else if (songAudio.getPitch() < 1) {
                        seconds = seconds * (1 + (1 - songAudio.getPitch()));
                    }
                    songAudio.setPlayingOffset(sf::seconds(songAudio.getPlayingOffset().asSeconds() - 15));
                    if (songAudio.getPlayingOffset().asSeconds() <= 0){
                        timeBar.setElapsedTime(0);
                        prevSongTime = 0;
                    } else {
                        timeBar.setElapsedTime(songAudio.getPlayingOffset().asSeconds() - 1);
                        prevSongTime = songAudio.getPlayingOffset().asSeconds() - 1;
                    }
                }
                thread->launch();
                rewind.disableState(CLICKED);
            }

            if (togglePlayBack.checkState(CLICKED)) {
                if (songAudio.getStatus() == sf::SoundSource::Playing) {
                    songAudio.pause();
                    timeBar.setUpdating(false);
                } else {
                    if (songAudio.getStatus() == sf::SoundSource::Stopped){
                        timeBar.resetBar();
                        prevSongTime = 0;
                    }
                    songAudio.play();
                    timeBar.setUpdating(true);
                    thread->launch();
                }
                togglePlayBack.disableState(CLICKED);
            }
        }

        if (forward.checkState(CLICKED)) {
            if (songAudio.getStatus() == sf::SoundSource::Stopped){
                timeBar.resetBar();
                prevSongTime = 0;
                songAudio.play();
                timeBar.setUpdating(true);
            } else {
                float seconds = 15;
                if (songAudio.getPitch() > 1) {
                    seconds = seconds * (1 - (songAudio.getPitch() - 1));
                } else if (songAudio.getPitch() < 1) {
                    seconds = seconds * (1 + (1 - songAudio.getPitch()));
                }
                songAudio.setPlayingOffset(sf::seconds(songAudio.getPlayingOffset().asSeconds() + 15));
                timeBar.setElapsedTime(songAudio.getPlayingOffset().asSeconds() - 1);
                prevSongTime = songAudio.getPlayingOffset().asSeconds() - 1;
            }
            thread->launch();
            forward.disableState(CLICKED);
        }
    }


}

void SongAndManipulations::update() {

    if (isSongLoaded){
        timeBar.update();
    }

    if (textBox.getIsValidNoSkip()){
        calcPosOfSkipRect(textBox.getTypedString());
    }


    textBox.update();

    tree.update();
    menu.update();
    drop.update();

    rewind.update();
    togglePlayBack.update();
    forward.update();

    std::wstring temp = (L"\uE102");

    if (songAudio.getStatus() == sf::SoundSource::Playing){
        if (togglePlayBack.getString() != (L"\uE103")){
            togglePlayBack.setString(L"\uE103");
        }
    } else {
        if (togglePlayBack.getString() != (L"\uE102")){
            togglePlayBack.setString(L"\uE102");
        }

    }

    if (textBox.getIsSkip()){
        skipTo(textBox.getEnteredString());
        textBox.setIsSkip(false);
    }
}

sf::FloatRect SongAndManipulations::getGlobalBounds() const {
    return sf::FloatRect();
}

Snapshot &SongAndManipulations::getSnapShot() {
    Snapshot snapshot;
    return snapshot;
}

void SongAndManipulations::applySnapShot(const Snapshot &snapshot) {

}
