#ifndef WIELOMIAN_H_INCLUDED
#define WIELOMIAN_H_INCLUDED
#include <vector>
#include <iostream>

class wielomian{
private:
    std::vector<long double> vec;

public:
    wielomian();
    wielomian(long double x0);
    wielomian(long double x1, long double x0);
    void resize(int n);
    int stopien()const;
    void operator- ();
    long double operator[](int el)const;
    long double& operator[](int el);
    long double operator()(long double x)const;
    wielomian der()const;
    std::string ods();
    friend std::ostream & operator<< (std::ostream &wyjscie, const wielomian& wielo);
    friend wielomian& operator<< (wielomian& wielo, long double x);
    friend std::istream & operator>> (std::istream &wejscie, wielomian& wielo);
    friend wielomian operator+ (const wielomian& w1, const wielomian& w2);
    friend wielomian operator- (const wielomian& w1, const wielomian& w2);
    friend wielomian operator* (const wielomian& w1, const wielomian& w2);
  //  friend wielomian operator/ (const wielomian& w1, const wielomian& w2);
    wielomian horner(long double c);
};

#endif // WIELOMIAN_H_INCLUDED
