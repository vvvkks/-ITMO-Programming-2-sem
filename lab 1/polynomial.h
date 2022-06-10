//
// Created by Вика on 18.03.2022.
//

#ifndef LAB1_POLYNOMIAL_H
#define LAB1_POLYNOMIAL_H
#include <iostream>
#include <vector>


class Poly {
private:
    std::vector<double> coeff;

public:
    explicit Poly(size_t size);

    explicit Poly(std::vector<double> soska = {0});

    Poly(const Poly &csosa);

    ~Poly();

    Poly &operator=(const Poly &trap);


    Poly operator+(const Poly &trap);

    Poly operator-(const Poly &trap);

    friend std::ostream &operator<<(std::ostream &s, const Poly &c);

    friend std::istream &operator>>(std::istream &s, Poly &c);

    bool operator==(Poly &cringe);

    bool operator!=(Poly &cringe);


    Poly operator/(int c);

    Poly operator*(Poly &polynomial);

    double operator[](int c) const;

    double &operator[](int c);
};


Poly operator+=(Poly &t1, Poly &t2);

Poly operator-=(Poly &t1, Poly &t2);

Poly operator*=(Poly &t1, Poly &t2);

Poly operator/=(Poly t1, int c);
#endif //LAB1_POLYNOMIAL_H
