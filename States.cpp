//
// Created by super on 10/31/2023.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LAST_STATE; i++){
        states[static_cast<statesEnum>(i)] = false;
    }
}

bool States::checkState(statesEnum state) const {
    return states.at(state);
}

void States::enableState(statesEnum state) {
    states[state] = true;
}

void States::disableState(statesEnum state) {
    states[state] = false;
}

void States::toggleState(statesEnum state) {
    states[state] = !states[state];
}
