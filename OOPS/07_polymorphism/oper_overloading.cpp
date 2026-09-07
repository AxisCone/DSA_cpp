#include<iostream>
using namespace std;

class Complex{

private:
int real;
int imaginary;

public:

Complex(){

}

Complex(int real,int imaginary){
    this->real=real;
    this->imaginary=imaginary;
}

void display(){
    cout<<real<<"+"<<imaginary<<"i";
}

Complex operator+(Complex&c){
    Complex ans;  // default constructor req, because it is declared differently
    ans.real = real+c.real;
    ans.imaginary = imaginary+c.imaginary;

    return ans;
}


};


int main(){

Complex c1(3,4);
Complex c2(5,7);

Complex c3 = c1+c2;
c3.display();

}