#ifndef POLYNOMIAL_HPP_INCLUDED
#define POLYNOMIAL_HPP_INCLUDED
#include <vector>
#include <iostream>

class polynomial{
private:
    std::vector<long double> vec;

public:
    polynomial();
    polynomial(long double x0);
    polynomial(long double x1, long double x0);
    void resize(int n);
    int degree() const;
    void operator-();
    long double operator[](int el) const;
    long double& operator[](int el);
    long double operator()(long double x) const;
    polynomial derivative() const;
    std::string print();
    friend std::ostream & operator<<(std::ostream &wyjscie, const polynomial& wielo);
    friend polynomial& operator<<(polynomial& wielo, long double x);
    friend std::istream & operator>>(std::istream &wejscie, polynomial& wielo);
    friend polynomial operator+(const polynomial& w1, const polynomial& w2);
    friend polynomial operator-(const polynomial& w1, const polynomial& w2);
    friend polynomial operator*(const polynomial& w1, const polynomial& w2);
  //  friend polynomial operator/(const wielomian& w1, const wielomian& w2);
    polynomial horner(long double c);
};

polynomial operator+(const polynomial& w1, const polynomial& w2);
polynomial operator-(const polynomial& w1, const polynomial& w2);
polynomial operator*(const polynomial& w1, const polynomial& w2);
//polynomial operator/(const wielomian& w1, const wielomian& w2);

#endif // POLYNOMIAL_HPP_INCLUDED
