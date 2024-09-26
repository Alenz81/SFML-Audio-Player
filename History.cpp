//
// Created by super on 11/5/2023.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    if (!stack.empty()){
        stack.top().component->applySnapShot(stack.top().snapshot);
        stack.pop();
    }

}

bool History::empty() {
    return stack.empty();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}
