#include "Mirror.h"

#include <stdexcept>

Mirror::Mirror() {}

Mirror::Mirror(std::vector<int> anchors) : anchors(anchors) {}

Mirror::~Mirror() {}

std::unordered_set<Coordinate*> Mirror::toMirror(Space* space){
    if (space->getDimension() != anchors.size()) {
        throw std::invalid_argument("The dimension of space and anchors must be equal.");
    }
    int minX, maxX, minY, maxY;
    bool xflag = false, yflag = false;
    for (int i = 0; i < anchors.size(); i++) {
        if (anchors[i] == std::numeric_limits<int>::max()) {
            if (xflag) {
                throw std::invalid_argument("The anchors only be one max infinity value.");
            }
            minX = space->getMinLimits()->at(i);
            maxX = space->getMaxLimits()->at(i);
            xflag = true;
        }
        if (anchors[i] == std::numeric_limits<int>::min()) {
            if (yflag) {
                throw std::invalid_argument("The anchors only be one min infinity value.");
            }
            minY = space->getMinLimits()->at(i);
            maxY = space->getMaxLimits()->at(i);
            yflag = true;
        }
    }
    std::unordered_set<Coordinate*> projection;
    for (auto it = space->space.begin(); it != space->space.end(); it++) {
        if ((*it)->getVec() == anchors) {
            projection.insert(*it);
        }
    }
    return projection;
}

