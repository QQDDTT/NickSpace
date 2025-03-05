#ifndef SPACE_H
#define SPACE_H

#include "Element.h"
#include "Coordinate.h"

#include <vector>
#include <unordered_set>
#include <functional>

// 空间
class Space {
public:
    Space();
    Space(int dimension, std::vector<int> maxLimits, std::vector<int> minLimits);
    virtual ~Space();

    int getDimension() const;

    void addElement(Element* element);
    void setElement(Element* element);
    void removeElement(Element* element);

    std::vector<int>* getMaxLimits();
    std::vector<int>* getMinLimits();

    std::unordered_set<Element*> space;
private:
    int dimension;
    std::vector<int> maxLimits;
    std::vector<int> minLimits;

};

#endif // SPACE_H