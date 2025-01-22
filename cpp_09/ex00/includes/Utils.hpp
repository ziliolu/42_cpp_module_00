#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

class Utils {
    public:
        static std::string trim(const std::string& str);
        static bool isValidValue(int value);
        static bool isValidDate(std::string date);
};

#endif

