#ifndef SUBSPACE_H
#define SUBSPACE_H

#include "Element.h"
#include "Coordinate.h"
#include "Linker.h"
#include "Space.h"

#include <vector>
#include <unordered_set>
#include <functional>

// 子空间
class Pandora {
public:
    Pandora();
    Pandora(Element* center, double radius);
    virtual ~Pandora();

    void addLinker(Linker* linker);
    void removeLinker(Linker* linker);

    void loadSpace(Space* space);
private:
    Element* center;
    double radius;
    std::unordered_set<Coordinate*> subspace;
    std::vector<Linker*> linkers;

};

#endif // SUBSPACE_H