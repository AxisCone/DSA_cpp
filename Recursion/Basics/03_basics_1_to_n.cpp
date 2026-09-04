#include<iostream>
using namespace std;

// Printing numbers from 1 to n , using 1 parameters
// printing while returning

void count(int n){

    if(n==1){
        cout<<n<<" ";
        return;
    }

    count(n-1);
    cout<<n<<" ";

}


int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;

    count(n);

}