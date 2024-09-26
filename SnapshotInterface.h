//
// Created by super on 11/3/2023.
//

#ifndef PROJECT_1_SNAPSHOTINTERFACE_H
#define PROJECT_1_SNAPSHOTINTERFACE_H

#include "Snapshot.h"

class SnapshotInterface {
public:
    virtual Snapshot& getSnapShot() = 0;
    virtual void applySnapShot(const Snapshot& snapshot) = 0;
};


#endif //PROJECT_1_SNAPSHOTINTERFACE_H
