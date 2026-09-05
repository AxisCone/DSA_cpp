#include<iostream>
using namespace std;

int square_sum(int n){

    if(n<=0){
        return 0;
    }

    return (n*n)+square_sum(n-1);

}

int main(){

    int n;
    cout<<"Enter the terms for sum of squares of numbers: ";
    cin>>n;

    int sum = square_sum(n);
    cout<<"Sum of squares of "<<n<<" terms is: "<<sum;
}
