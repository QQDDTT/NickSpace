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
    // 构造函数
    Mirror();
    Mirror(std::vector<int> anchors);
    virtual ~Mirror();

    // 获取空间模型的镜像
    std::unordered_set<Coordinate*> toMirror(Space* space);

private:
    std::vector<int> anchors; // 镜像锚点，表示该镜像在空间的位置
};

#endif // MIRROR_H