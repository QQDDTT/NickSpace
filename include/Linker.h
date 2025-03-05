#ifndef LINKER_H
#define LINKER_H

#include "Element.h"

#include <string>
#include <functional>

// 链接
class Linker {
public:
    Linker();
    Linker(std::function<bool(Element* element1, Element* element2)> actionable, std::function<void(Element* element1, Element* element2)> action);
    virtual ~Linker();

    virtual bool actionable(Element* element1, Element* element2);    // 可行性判断
    virtual void action(Element* element1, Element* element2);    // 交互
private:
    std::function<bool(Element*, Element*)> actionableFunc;  // 可行性判断
    std::function<void(Element*, Element*)> actionFunc;  // 交互操作
};

bool isNear(Element* element1, Element* element2);
void exchange(Element* element1, Element* element2);

#endif // LINKER_H