#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "Coordinate.h"
#include <functional>

// Element 类继承自 Coordinate
class Element : public Coordinate {
public:
    Element();
    Element(std::string name, std::string style, std::string describe);
    virtual ~Element();

    const int getDimension() const override;

    const std::string& getName() const;
    const std::string& getStyle() const;
    
    const std::string& getDescribe() const;

    bool operator==(const Element& other) const;
    bool operator==(std::vector<int> other) const;

    // 重载 hash 函数
    size_t hash() const override {
        return Coordinate::hash();
    };

    const std::vector<int>& getVec() const {
        return vec;
    }

    void setVec(const std::vector<int>& vec) {
        this->vec = vec;
    }

private:
    std::string name;
    std::string style;
    std::string describe;
};

#endif // ELEMENT_H