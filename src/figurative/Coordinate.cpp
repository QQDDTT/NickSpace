#include "Coordinate.h"

#include <cmath>

Coordinate::Coordinate() : dimension(2) , vec{0, 0} {}

Coordinate::Coordinate(std::initializer_list<int> list) : dimension(list.size()), vec(list) {}

Coordinate::Coordinate(const std::vector<int>& vec) : dimension(vec.size()), vec(vec) {}

const int Coordinate::getDimension() const {
    return dimension;
}

std::string Coordinate::toString() const {
    std::string result = "(";
    for (int i = 0; i < dimension; i++) {
        result += std::to_string(vec[i]);
        if (i < dimension - 1) {
            result += ", ";
        }
    }
    result += ")";
    return result;
}

double Coordinate::getMod() const {
    int n = 0;
    for (int i = 0; i < dimension; i++) {
        n += vec[i] * vec[i];
    }
    return std::sqrt(n);
}

Coordinate Coordinate::operator+(const Coordinate& other) const {
    std::vector<int> result(dimension);
    for (int i = 0; i < dimension; i++) {
        result[i] = vec[i] + other.vec[i];
    }
    return Coordinate(result);
}

Coordinate Coordinate::operator-(const Coordinate& other) const {
    std::vector<int> result(dimension);
    for (int i = 0; i < dimension; i++) {
        result[i] = vec[i] - other.vec[i];
    }
    return Coordinate(result);
}

bool Coordinate::operator==(const Coordinate& other) const {
    if (dimension != other.dimension) {
        return false;
    }
    for (int i = 0; i < dimension; i++) {
        if (vec[i] != other.vec[i]) {
            return false;
        }
    }
    return true;
}

bool Coordinate::operator==(std::vector<int> other) const {
    if (dimension != other.size()) {
        return false;
    }
    for (int i = 0; i < dimension; i++) {
        if (other[i] != std::numeric_limits<int>::max() && other[i] != std::numeric_limits<int>::min() && vec[i] != other[i]) {
            return false;
        }
    }
    return true;
}