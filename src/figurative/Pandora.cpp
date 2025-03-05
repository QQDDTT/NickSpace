#include "Pandora.h"


#include <stdexcept>

Pandora::Pandora() : center(nullptr), radius(0){}

Pandora::Pandora(Element* center, double radius) : center(center), radius(radius){}

Pandora::~Pandora(){}

void Pandora::addLinker(Linker* linker) {
    linkers.push_back(linker);
}

void Pandora::removeLinker(Linker* linker) {
    linkers.erase(std::remove(linkers.begin(), linkers.end(), linker), linkers.end());
}

void Pandora::loadSpace(Space* space){
    if (space->getDimension() != center->getDimension()){
        throw std::invalid_argument("The dimension of space and centerCoordinate must be equal.");
    }
    for (auto it = space->space.begin(); it != space->space.end(); it++){
        if ((dynamic_cast<Coordinate*>(center) - dynamic_cast<Coordinate*>(*it)) <= radius){
            subspace.insert(*it);
        }
    }
}

