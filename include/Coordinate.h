#ifndef COORDINATE_H
#define COORDINATE_H

#include <vector>
#include <string>
#include <functional>
#include <limits>

// N 维坐标
class Coordinate {
public:
    // 默认构造函数
    Coordinate();

    // N 维坐标构造
    Coordinate(std::initializer_list<int> list);
    Coordinate(const std::vector<int>& vec);

    // 获取维度大小
    virtual const int getDimension() const;

    // 转换为字符串
    std::string toString() const;

    // 取模
    double getMod() const;

    // 运算符重载
    Coordinate operator+(const Coordinate& other) const;
    Coordinate operator-(const Coordinate& other) const;
    bool operator==(const Coordinate& other) const;
    bool operator==(std::vector<int> other) const;

protected:
    int dimension;
    std::vector<int> vec;

    virtual size_t hash() const {
        size_t hashValue = 0;
        std::hash<int> intHash;
        for (int i = 0; i < dimension; i++) {
            hashValue ^= intHash(vec[i]) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
        }
        return hashValue;
    }
};

#endif // COORDINATE_H
