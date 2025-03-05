#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include <ctime>
#include <string>

struct DateTime
{
    static std::string getDateTime() {
        return getDate() + " " + getTime();
    }
    
    static std::string getDate() {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        return std::to_string(localTime->tm_year + 1900) + "-" + std::to_string(localTime->tm_mon + 1) + "-" + std::to_string(localTime->tm_mday);
    }
    
    static std::string getTime() {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        return std::to_string(localTime->tm_hour) + ":" + std::to_string(localTime->tm_min) + ":" + std::to_string(localTime->tm_sec);  
    }
};

#endif // DATE_TIME_HPP