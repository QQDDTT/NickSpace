#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "Coordinate.h"
#include <functional>

// Element 类继承自 Coordinate
class Element : public Coordinate {
public:
    // 构造函数
    Element();
    Element(std::string name, std::string style, std::string describe);
    virtual ~Element();

    // 获取维度
    const int getDimension() const override;

    // 获取名称
    const std::string& getName() const;

    // 获取样式
    const std::string& getStyle() const;
    
    // 获取描述
    const std::string& getDescribe() const;

    // 运算符重载
    bool operator==(const Element& other) const;
    bool operator==(std::vector<int> other) const;

    // 重载 hash 函数
    size_t hash() const override {
        return Coordinate::hash();
    };

    // 获取坐标
    const std::vector<int>& getVec() const {
        return vec;
    }

    // 设置坐标
    void setVec(const std::vector<int>& vec) {
        this->vec = vec;
    }

private:
    std::string name; // 名称
    std::string style; // 样式
    std::string describe; // 描述
};

#endif // ELEMENT_H