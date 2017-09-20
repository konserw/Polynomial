#include "wielomian.h"
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>
//using std::cout;

wielomian::wielomian(){
}
wielomian::wielomian(long double x0){
    vec.push_back(x0);
}
wielomian::wielomian(long double x1, long double x0){//incjalizacja jako dwumian x1+xo
    vec.push_back(x0);
    vec.push_back(x1);
}
void wielomian::resize(int n){
    for(int i=0; i<=n; i++)
        vec.push_back(0);
}
int wielomian::stopien()const{
    return vec.size()-1;
}
void wielomian::operator- (){
    for(int i=0; i<vec.size(); i++){
        vec[i] = -vec[i];
    }
}
std::ostream & operator<< (std::ostream &wyjscie, const wielomian& wielo){
    for(int i=wielo.stopien(); i>=0; i--){
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
std::istream & operator>> (std::istream &wejscie, wielomian& wielo){
    long double x;
    wejscie >> x;
    wielo.vec.push_back(x);
    return wejscie;
}
wielomian& operator<< (wielomian& wielo, long double x){
//    long double x;
  //  wejscie >> x;
    wielo.vec.push_back(x);
    return wielo;
}
wielomian operator+ (const wielomian& w1, const wielomian& w2){
    int n;
    if(w1.stopien() > w2.stopien()) n=w1.stopien();
    else n=w2.stopien();
    wielomian temp;

    for(int i=0; i<=n; i++){
        temp << w1[i]+w2[i];
    }
    return temp;
}
wielomian operator- (const wielomian& w1, const wielomian& w2){
    wielomian temp;
    temp = w2;
    -temp;
    return w1 + temp;
}
wielomian operator* (const wielomian& w1, const wielomian& w2){
    int m = w1.stopien();
    int n = w2.stopien();
    wielomian temp;
    temp.resize(m+n);

//    std::ofstream cout("log");
//    cout << m << "\t" << n << "\n";
 //   cout << "stopien tempa: " << temp.vec.size() << "\ntemp:\t" << temp << "\n";
    for (int i = 0; i <= m; i++) {
   //     cout << "i: " << i << "\n";
        for (int j = 0; j <= n; j++) {
     //       cout << "\tj: " << j << "\tw1[i]: " << w1[i] << "\tw2[j]: " << w2[j];
            temp.vec[i + j] += w1[i] * w2[j];
       //     cout << "\ttemp[i+j]: " << temp.vec[i + j] << "\n";
        }
    }
  //  cout << "temp:\t" << temp <<"\n";
    return temp;
}

long double& wielomian::operator[](int el)
{
    return vec[el];
}

long double wielomian::operator[](int el) const
{
    if(vec.size() > el)
        return vec[el];
    else return 0;
}
long double wielomian::operator()(long double x)const{
    long double r=0;
    for(int i=0; i<vec.size(); i++){
        r += vec[i]*pow(x, i);
    }
    return r;
}
wielomian wielomian::der()const{
    wielomian t;
    for(int i=1; i<vec.size(); i++){
        t << vec[i]*i;
    }
    return t;
}
std::string wielomian::ods()
{
    std::stringstream ss;
    for(std::vector<long double>::iterator i=vec.begin(); i<vec.end(); ++i)
    {
        ss << std::setprecision(7) << *i << "\n";
    }
    return ss.str();
}

wielomian wielomian::horner(long double c)
{
    wielomian w;
    int n = this->stopien();
    w.resize(n-1);
    w[n-1] = vec[n];
    for(int i=n-1; i>0; i--)
    {
      w[i-1] = vec[i] + c*vec[i];
    }
    return w;
}
