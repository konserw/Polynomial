#include "polynomial.hpp"
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>

polynomial::polynomial(long double x0) {
    coefficients.push_back(x0);
}

polynomial::polynomial(long double x1, long double x0) {
    coefficients.push_back(x0);
    coefficients.push_back(x1);
}

void polynomial::resize(int n) {
    for(int i=0; i<=n; i++)
        coefficients.push_back(0);
}

bool polynomial::isEmpty() const
{
    return coefficients.empty();
}

int polynomial::degree() const {
    return coefficients.size()-1;
}

void polynomial::operator-() {
    for(int i=0; i<coefficients.size(); i++){
        coefficients[i] = -coefficients[i];
    }
}

std::ostream & operator<<(std::ostream &output, const polynomial& w) {
    for(int i=w.degree(); i>=0; i--){
        if(w[i]){
            output << w[i];
            if(i){
                output << "x^" << i << " ";
                if(w[i-1] > 0) output << "+";
            }
        }
    }
    return output;
}

std::istream & operator>>(std::istream &input, polynomial& w) {
    long double x;
    input >> x;
    w.coefficients.push_back(x);
    return input;
}

polynomial& operator<<(polynomial& w, long double x) {
    w.coefficients.push_back(x);
    return w;
}

polynomial operator+(const polynomial& w1, const polynomial& w2) {
    int n;
    if(w1.degree() > w2.degree()) n=w1.degree();
    else n=w2.degree();
    polynomial temp;

    for(int i=0; i<=n; i++){
        temp << w1.at(i) + w2.at(i);
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
            temp.coefficients[i + j] += w1[i] * w2[j];
        }
    }
    return temp;
}

long double& polynomial::operator[](size_t k) {
    return coefficients[k];
}

std::string polynomial::print() const {
    std::stringstream temp;
    /*
    for (int i=w.degree(); i>=0; --i) {
        if (w[i]) {
            temp << w[i];
            if (i) {
                temp << "x^" << i << " ";
                if (w[i-1] > 0) {
                    temp << "+";
                }
            }
        }
    }*/
    temp << *this;
    return temp.str();
}

const long double& polynomial::operator[](size_t k) const {
    return coefficients[k];
}

long double polynomial::operator()(long double x) const {
    long double r=0;
    for(int i=0; i<coefficients.size(); i++) {
        r += coefficients[i]*pow(x, i);
    }
    return r;
}

polynomial polynomial::derivative() const {
    polynomial t;
    for(int i=1; i<coefficients.size(); i++) {
        t << coefficients[i]*i;
    }
    return t;
}

std::string polynomial::printVector(char sep, int precision) const {
    std::stringstream ss;
    ss << "[" << sep;
    for(auto i=coefficients.cbegin(); i<coefficients.cend(); ++i) {
        ss << std::setprecision(precision) << *i << sep;
    }
    ss << "]" << sep;
    return ss.str();
}

std::string polynomial::printVerticalVector(int precision) const {
    return printVector('\n', precision);
}

std::string polynomial::printHorizontalVector(int precision) const {
    return printVector(' ', precision);
}

long double polynomial::at(size_t k) const {
    if(k < coefficients.size())
        return coefficients[k];
    else return 0;
}

polynomial polynomial::horner(long double c) {
    polynomial w;
    int n = this->degree();
    w.resize(n-1);
    w[n-1] = coefficients[n];
    for(int i=n-1; i>0; i--) {
        w[i-1] = coefficients[i] + c*coefficients[i];
    }
    return w;
}
