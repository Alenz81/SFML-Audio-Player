//
// Created by super on 11/5/2023.
//

#ifndef PROJECT_1_HISTORYNODE_H
#define PROJECT_1_HISTORYNODE_H

#include "Snapshot.h"
#include "GUIComponent.h"

struct HistoryNode
{
    Snapshot snapshot;
    GUIComponent* component;
};

#endif //PROJECT_1_HISTORYNODE_H
