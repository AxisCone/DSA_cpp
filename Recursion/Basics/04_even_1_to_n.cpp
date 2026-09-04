#include<iostream>
using namespace std;

// Printing EVEN numbers from 1 to n , using 1 parameters
// printing while returning

void print_even(int n){

    if(n==1){
        if(n%2==0){
            cout<<n<<" ";            
        }
        return;
    }

    print_even(n-1);

    if(n%2==0){
      cout<<n<<" ";
    }

}


int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;

    print_even(n);

}