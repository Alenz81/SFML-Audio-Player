//
// Created by super on 11/5/2023.
//

#ifndef PROJECT_1_SNAPSHOT_H
#define PROJECT_1_SNAPSHOT_H

#include <iostream>
#include <stack>
#include <vector>
#include "States.h"

class Snapshot {
public:
    std::vector<std::string> stringDatas;
    std::vector<std::vector<statesEnum>> stateDatas;
    
    Snapshot();

    void pushStringData(const std::string& string);
    void addStateData(statesEnum state, int index);
    void resizeStates(int size);

    void operator = (const Snapshot& snapshot);

};


#endif //PROJECT_1_SNAPSHOT_H
