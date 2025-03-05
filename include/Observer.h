#ifndef OBSERVER_H
#define OBSERVER_H

#include "Element.h"
#include "Space.h"

// 观察者
class Observer {
public:
    Observer();
    virtual ~Observer();
    void operate<<(Space space);
    void operate<<(Subspace subspace);
    void operate<<(Projection projection);
    void operate<<(Linker linker);
    void operate<<(Element* element);
};

extern Observer console;
extern Observer logger;


#endif // OBSERVER_H