//
// Created by super on 11/5/2023.
//

#include "Snapshot.h"

Snapshot::Snapshot() {

}

void Snapshot::pushStringData(const std::string& string) {
    stringDatas.push_back(string);
}

void Snapshot::addStateData(statesEnum state, int index) {
    if (index < stateDatas.size() - 1){
        stateDatas.resize(index + 1);
    }
    stateDatas.at(index).push_back(state);
}

void Snapshot::resizeStates(int size) {
    stateDatas.resize(size);
}

void Snapshot::operator=(const Snapshot &snapshot) {
    stringDatas.clear();
    stateDatas.clear();


    if (!snapshot.stringDatas.empty()) {
        for (int i = 0; i < snapshot.stringDatas.size(); i++) {
            stringDatas.push_back(snapshot.stringDatas.at(i));
        }
    }
    if (!snapshot.stateDatas.empty()) {
        for (int i = 0; i < snapshot.stateDatas.size(); i++) {
            stateDatas.push_back(snapshot.stateDatas.at(i));
        }
    }
}
