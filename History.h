//
// Created by super on 11/5/2023.
//

#ifndef PROJECT_1_HISTORY_H
#define PROJECT_1_HISTORY_H

#include "HistoryNode.h"
#include <stack>

class History {
private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static bool empty();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //PROJECT_1_HISTORY_H
