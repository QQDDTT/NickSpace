#ifndef MIRROR_H
#define MIRROR_H

#include "Space.h"
#include "Element.h"
#include "Coordinate.h"

#include <vector>
#include <unordered_set>
#include <functional>

// 镜像
class Mirror {
public:
    Mirror();
    Mirror(std::vector<int> anchors);
    virtual ~Mirror();

    std::unordered_set<Coordinate*> toMirror(Space* space);

private:
    std::vector<int> anchors;
};

#endif // MIRROR_H