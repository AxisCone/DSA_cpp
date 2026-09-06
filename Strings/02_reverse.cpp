#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    string s = "FUND JET ENGINE PROGRAM ";
    string z = "STOP FREEBIES";
    int start=0;
    int end = s.size()-1;

    // Methood 1
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }

    reverse(z.begin(),z.end());    // Methood 2

    cout<<"Reversed String 1: "<<s<<endl;
    cout<<"Reversed String 2: "<<z;


}