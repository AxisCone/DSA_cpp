#include<iostream>
using namespace std;

void birthday(int n){
     // Base Case
    if(n == 0){
        cout << "Happy Birthday!" << endl;
        return;
    }
    
    // Recursive Cases
    if(n == 1){
        cout << n << " day left for Birthday" << endl;
        birthday(n - 1); 
    }
    else{
        cout << n << " days left for Birthday" << endl;
        birthday(n - 1);        
    }
}

int main(){
    int n;
    cout << "Enter the number of days left for birthday: ";
    cin >> n;

    birthday(n);
    return 0; 
}