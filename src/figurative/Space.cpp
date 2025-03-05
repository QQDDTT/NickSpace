#include "Space.h"
#include <stdexcept>

Space::Space() : dimension(2), maxLimits({99, 99}), minLimits({0, 0}) {}

Space::Space(int dimension, std::vector<int> maxLimits, std::vector<int> minLimits)
    : dimension(dimension), maxLimits(maxLimits), minLimits(minLimits) {}

Space::~Space() {}

int Space::getDimension() const {
    return dimension;
}

// 添加元素
void Space::addElement(Element* element) {
    if (element->getDimension() != dimension) {
        throw std::invalid_argument("The dimension of element must be equal to the dimension of space.");
    }
    if (space.find(element) != space.end()) {
        throw std::invalid_argument("The element already exists.");
    }
    space.insert(element);
}

// 设置元素
void Space::setElement(Element* element) {
    if (element->getDimension() != dimension) {
        throw std::invalid_argument("The dimension of element must be equal to the dimension of space.");
    }
    // 这里假设只有空间中不存在该元素才允许插入
    if (space.find(element) == space.end()) {
        throw std::invalid_argument("The element is unexpected.");
    }
    space.insert(element);
}

// 移除元素
void Space::removeElement(Element* element) {
    if (space.find(element) == space.end()) {
        throw std::invalid_argument("The element is unexpected.");
    }
    space.erase(element);
}

// 获取最大限制
std::vector<int>* Space::getMaxLimits() {
    return &maxLimits;
}

// 获取最小限制
std::vector<int>* Space::getMinLimits() {
    return &minLimits;
}
