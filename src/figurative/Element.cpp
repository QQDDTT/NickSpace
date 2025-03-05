#include "Element.h"

Element::Element() : name(""), style(""), describe("") {}

Element::Element(std::string name, std::string style, std::string describe)
    : name(name), style(style), describe(describe) {}

Element::~Element() {}

const int Element::getDimension() const {
    return Coordinate::getDimension();
}

const std::string& Element::getName() const {
    return name;
}

const std::string& Element::getStyle() const {
    return style;
}

const std::string& Element::getDescribe() const {
    return describe;
}

bool Element::operator==(const Element& other) const {
    // Compare the Coordinate part (using the Coordinate class's operator==)
    return static_cast<const Coordinate&>(*this) == static_cast<const Coordinate&>(other) &&
           name == other.name && style == other.style;
}

bool Element::operator==(std::vector<int> other) const {
    // Compare the Coordinate part (using the Coordinate class's operator==)
    return static_cast<const Coordinate&>(*this) == other;
}