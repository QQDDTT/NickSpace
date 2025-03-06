#ifndef LINKER_H
#define LINKER_H

#include "Element.h"

#include <string>
#include <functional>

// 链接
class Linker {
public:
    // 构造函数
    Linker();
    Linker(std::function<bool(Element* element1, Element* element2)> actionable, std::function<void(Element* element1, Element* element2)> action);
    virtual ~Linker();

    // 可行性判断函数
    virtual bool actionable(Element* element1, Element* element2);

    // 执行函数
    virtual void action(Element* element1, Element* element2);
private:
    std::function<bool(Element*, Element*)> actionableFunc;  // 可行性判断函数
    std::function<void(Element*, Element*)> actionFunc;  // 执行函数
};

bool isNear(Element* element1, Element* element2); // 判断两个元素是否相邻
void exchange(Element* element1, Element* element2); // 交换两个元素

#endif // LINKER_H