//
// Created by super on 10/31/2023.
//

#include "Application.h"

std::vector<GUIComponent*> Application::components;

void Application::addComponent(GUIComponent &component) {
    components.push_back(&component);
}



void Application::run() {
    sf::RenderWindow window(Engine::getWorkingWindowSize(), "SFML Audio Player"); //parametrize these
    window.setFramerateLimit(60);
    //sf::Clock delay;
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            } else {

                for (GUIComponent *&component: components) {
                    component->eventHandler(window, event);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !History::empty()/* && delay.getElapsedTime().asSeconds() > 0.1*/){
                    History::popHistory();
                    //delay.restart();
                }
            }
        }
        for (GUIComponent* &component : components){
            component->update();
        }

        window.clear(sf::Color::Black);
        for (GUIComponent* &component : components){
            window.draw(*component);
        }

        window.display();

    }
}
