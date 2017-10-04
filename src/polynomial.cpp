#include "polynomial.hpp"
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>

polynomial::polynomial() {
}

polynomial::polynomial(long double x0) {
    vec.push_back(x0);
}

polynomial::polynomial(long double x1, long double x0) {
    vec.push_back(x0);
    vec.push_back(x1);
}

void polynomial::resize(int n) {
    for(int i=0; i<=n; i++)
        vec.push_back(0);
}

int polynomial::degree() const {
    return vec.size()-1;
}

void polynomial::operator-() {
    for(int i=0; i<vec.size(); i++){
        vec[i] = -vec[i];
    }
}

std::ostream & operator<<(std::ostream &wyjscie, const polynomial& wielo) {
    for(int i=wielo.degree(); i>=0; i--){
        if(wielo[i]){
            wyjscie << wielo[i];
            if(i){
                wyjscie << "x^" << i << " ";
                if(wielo[i-1] > 0) wyjscie << "+";
            }
        }
    }
    return wyjscie;
}

std::istream & operator>>(std::istream &wejscie, polynomial& wielo) {
    long double x;
    wejscie >> x;
    wielo.vec.push_back(x);
    return wejscie;
}

polynomial& operator<<(polynomial& wielo, long double x) {
    wielo.vec.push_back(x);
    return wielo;
}

polynomial operator+(const polynomial& w1, const polynomial& w2) {
    int n;
    if(w1.degree() > w2.degree()) n=w1.degree();
    else n=w2.degree();
    polynomial temp;

    for(int i=0; i<=n; i++){
        temp << w1[i]+w2[i];
    }
    return temp;
}

polynomial operator-(const polynomial& w1, const polynomial& w2) {
    polynomial temp;
    temp = w2;
    -temp;
    return w1 + temp;
}

polynomial operator*(const polynomial& w1, const polynomial& w2) {
    int m = w1.degree();
    int n = w2.degree();
    polynomial temp;
    temp.resize(m+n);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            temp.vec[i + j] += w1[i] * w2[j];
        }
    }
    return temp;
}

long double& polynomial::operator[](int el) {
    return vec[el];
}

long double polynomial::operator[](int el) const {
    if(vec.size() > el)
        return vec[el];
    else return 0;
}

long double polynomial::operator()(long double x) const {
    long double r=0;
    for(int i=0; i<vec.size(); i++) {
        r += vec[i]*pow(x, i);
    }
    return r;
}

polynomial polynomial::derivative() const {
    polynomial t;
    for(int i=1; i<vec.size(); i++) {
        t << vec[i]*i;
    }
    return t;
}

std::string polynomial::print() {
    std::stringstream ss;
    for(std::vector<long double>::iterator i=vec.begin(); i<vec.end(); ++i)
    {
        ss << std::setprecision(7) << *i << "\n";
    }
    return ss.str();
}

polynomial polynomial::horner(long double c) {
    polynomial w;
    int n = this->degree();
    w.resize(n-1);
    w[n-1] = vec[n];
    for(int i=n-1; i>0; i--) {
        w[i-1] = vec[i] + c*vec[i];
    }
    return w;
}
