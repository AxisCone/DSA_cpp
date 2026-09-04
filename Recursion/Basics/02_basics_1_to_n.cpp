#include<iostream>
using namespace std;
 
// Print numbers from 1 to n using two parameters 

void count(int num , int n){

    if(num==n){

        cout<<num<<" ";
        return;
    }

    cout<<num<<" ";

    count(num+1,n);

}


int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;

    count(1,n);

}