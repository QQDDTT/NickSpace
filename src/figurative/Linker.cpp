#include "Linker.h"

Linker::Linker() : actionableFunc(&isNear), actionFunc(nullptr) {}

Linker::Linker(std::function<bool(Element* element1, Element* element2)> actionable, std::function<void(Element* element1, Element* element2)> action) : actionableFunc(actionable), actionFunc(action) {}

Linker::~Linker() {}

bool Linker::actionable(Element* element1, Element* element2) {
    if (actionableFunc != nullptr) {
        return actionableFunc(element1, element2);
    }
    return false;
}

void Linker::action(Element* element1, Element* element2) {
    if (actionFunc != nullptr && actionableFunc(element1, element2)) {
        actionFunc(element1, element2);
    }
}

bool isNear(Element* element1, Element* element2) {
    // Directly use the Coordinate part of the Element class
    return (static_cast<const Coordinate&>(*element1) - static_cast<const Coordinate&>(*element2)).getMod() <= 2;
}

void exchange(Element* element1, Element* element2) {
    std::vector<int> temp = element1->getVec();  // Use the getter method to access vec
    element1->setVec(element2->getVec());
    element2->setVec(temp);
}

