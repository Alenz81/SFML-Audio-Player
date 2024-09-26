//
// Created by super on 10/31/2023.
//

#ifndef STATES_EXANOKE_APPLICATION_H
#define STATES_EXANOKE_APPLICATION_H

#include <vector>
#include "GUIComponent.h"
#include "History.h"
#include "Engine.h"

class Application {
private:
    static std::vector<GUIComponent*> components;
public:
    static void addComponent(GUIComponent& component);
    static void run();

};


#endif //STATES_EXANOKE_APPLICATION_H
