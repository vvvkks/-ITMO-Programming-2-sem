#ifndef CUBE_EXCEPTION_H
#define CUBE_EXCEPTION_H
#include <iostream>

class Exception: public std::exception {
    std::string error;
public:
    explicit Exception(std::string);

    [[nodiscard]] const char * what() const noexcept override;
};

#endif
