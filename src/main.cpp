#include "DateTime.hpp"
#include "Coordinate.h"

#include <string>
#include <iostream>

int main() {
    std::cout <<  DateTime::getDateTime() << "Start:" << std::endl;

    std::cout <<  DateTime::getDateTime() << "End:" << std::endl;
    return 0;
}
