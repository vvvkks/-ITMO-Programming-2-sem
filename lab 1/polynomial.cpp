
#include "polynomial.h"

Poly::Poly(size_t size) {
    coeff.resize(size);
}

Poly::Poly(std::vector<double> soska) {
    coeff = std::move(soska);
}

Poly::Poly(const Poly &csosa) : Poly(csosa.coeff) {}

Poly::~Poly() {
    coeff.clear();
}

Poly &Poly::operator=(const Poly &trap) {
    if (this != &trap) {
        for (int i = 0; i < trap.coeff.size(); i++) {
            coeff[i] = trap.coeff[i];
        }
    }
    return *this;
}

Poly Poly::operator+(const Poly &trap) {
    int i, j;
    Poly temp(std::max(trap.coeff.size(), coeff.size()));
    if (coeff.size() < trap.coeff.size()) {
        for (i = 0; i < coeff.size(); i++) {
            temp.coeff[i] = coeff[i] + temp.coeff[i];
        }
        for (j = i + 1; j < trap.coeff.size(); i++) {
            temp.coeff[j] = trap.coeff[j];
        }
    } else {
        for (i = 0; i < trap.coeff.size(); i++) {
            temp.coeff[i] = coeff[i] + trap.coeff[i];
        }
        for (j = i + 1; j < coeff.size(); i++) {
            temp.coeff[j] = coeff[j];
        }
    }
    return temp;
}

Poly Poly::operator-(const Poly &trap) {
    int i, j;
    Poly temp(std::max(trap.coeff.size(), coeff.size()));
    if (coeff.size() < trap.coeff.size()) {
        for (i = 0; i < coeff.size(); i++) {
            temp.coeff[i] = coeff[i] - temp.coeff[i];
        }
        for (j = i + 1; j < trap.coeff.size(); i++) {
            temp.coeff[j] = trap.coeff[j];
        }
    } else {
        for (i = 0; i < trap.coeff.size(); i++) {
            temp.coeff[i] = coeff[i] - trap.coeff[i];
        }
        for (j = i + 1; j < coeff.size(); i++) {
            temp.coeff[j] = coeff[j];
        }
    }
    return temp;
}

std::ostream &operator<<(std::ostream &s, const Poly &c) {
    for (size_t i = 0; i < c.coeff.size(); ++i) {
        s << ((c.coeff[i] >= 0) ? "+" : "") << c.coeff[i] << "*x^" << i << ' ';
    }
    return s;
}

std::istream &operator>>(std::istream &s, Poly &c) {
    int t;
    std::cout << "Input number of coeff: ";
    std::cin >> t;
    c.coeff.resize(t);
    for (size_t i = 0; i < t; ++i) {
        s >> c.coeff[i];
    }
    return s;
}

Poly operator+=(Poly &t1, Poly &t2) {
    return t1 = t1 + t2;
}

Poly operator-=(Poly &t1, Poly &t2) {
    return t1 = t1 - t2;
}

Poly operator*=(Poly &t1, Poly &t2) {
    return t1 = t1 * t2;
}

Poly operator/=(Poly t1, const int c) {
    t1 = t1 / c;
    return t1;
}

bool Poly::operator==(Poly &cringe) {
    if (cringe.coeff.size() != coeff.size()) {
        return false;
    }
    for (size_t i = 0; i < cringe.coeff.size(); ++i) {
        if (cringe.coeff[i] != coeff[i]) {
            return false;
        }
    }
    return true;
}

bool Poly::operator!=(Poly &cringe) {
    return !(*this == cringe);
}

Poly Poly::operator/(const int c) {
    Poly results(coeff.size());
    for (size_t i = 0; i < coeff.size(); i++) {
        results.coeff[i] = coeff[i] / c;
    }
    return results;
}

Poly Poly::operator*(Poly &polynomial) {
    Poly result(polynomial.coeff.size() + this->coeff.size());
    for (size_t i = 0; i < polynomial.coeff.size(); i++)
        for (size_t j = 0; j < coeff.size(); j++)
            result.coeff[i + j] = coeff[j] * polynomial.coeff[i];
    return result;
}

double Poly::operator[](int c) const {
    return coeff[c];
}

double &Poly::operator[](int c) {
    return coeff[c];
}
