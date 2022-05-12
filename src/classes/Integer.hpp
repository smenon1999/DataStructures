#ifndef INTEGER
#define INTEGER
#include <string>

namespace DataTypes {
    struct Integer {
        int data;
        std::string to_string() {
            return std::to_string(data);
        }
    };
}

#endif