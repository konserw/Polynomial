#ifndef POLYNOMIAL_HPP_INCLUDED
#define POLYNOMIAL_HPP_INCLUDED
#include <vector>
#include <iostream>

class polynomial{
private:
    std::vector<long double> coefficients;

public:
    //constructors
    polynomial() = default;
    polynomial(long double x0);
    polynomial(std::initializer_list<long double> list);
    ~polynomial() = default;

    //other
    void resize(int n);
    bool isEmpty() const;
    int degree() const;
    polynomial derivative() const;
    polynomial horner(long double c);
    long double operator()(long double x) const;

    //accessors and mutators
    long double at(size_t k) const;
    const long double& operator[](size_t k) const;
    long double& operator[](size_t k);
    friend polynomial& operator<<(polynomial& wielo, long double x);
    friend std::istream & operator>>(std::istream &input, polynomial& wielo);

    //printing
    std::string print() const;
    std::string printVector(char sep = ' ', int precision = 7) const;
    std::string printVerticalVector(int precision = 7) const;
    std::string printHorizontalVector(int precision = 7) const;
    friend std::ostream & operator<<(std::ostream &putput, const polynomial& w);

    //arithmetic
    void operator-();
    friend polynomial operator+(const polynomial& w1, const polynomial& w2);
    friend polynomial operator-(const polynomial& w1, const polynomial& w2);
    friend polynomial operator*(const polynomial& w1, const polynomial& w2);
  //  friend polynomial operator/(const wielomian& w1, const wielomian& w2);

    //comparison
    friend bool operator==(polynomial const &a, polynomial const &b) { return a.coefficients == b.coefficients; }
    friend bool operator!=(polynomial const &a, polynomial const &b) { return a.coefficients != b.coefficients; }
};

#endif // POLYNOMIAL_HPP_INCLUDED
