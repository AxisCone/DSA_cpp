#include<iostream>
using namespace std;

int factorial(int n){

    if(n==1){
        return 1;
    }

    return n*factorial(n-1);

}

int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;

    int x = factorial(n);

    cout<<"Factorial of "<<n<<" is: "<<x;

}