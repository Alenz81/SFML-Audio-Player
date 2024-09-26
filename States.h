//
// Created by super on 10/31/2023.
//

#ifndef SFML_Audio_Player_STATES_H
#define SFML_Audio_Player_STATES_H
#include "StatesEnum.h"
#include <map>


class States {
private:
    std::map<statesEnum, bool> states;
public:
    States();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void toggleState(statesEnum state);

};


#endif //SFML_Audio_Player_STATES_H
