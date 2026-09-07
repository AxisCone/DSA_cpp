#include<iostream>
using namespace std;

class Area{

public:
    int CalculateArea(int r){
        return 3.14*r*r;
    }

    int CalculateArea(int l,int b){
        return l*b;
    }

};

int main(){

Area A1,A2;
cout<<"Area of circle: "<<A1.CalculateArea(12)<<endl;
cout<<"Area of rectangle: "<<A2.CalculateArea(7,9)<<endl;


}

