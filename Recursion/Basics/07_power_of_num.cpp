#include<iostream>
using namespace std;

// takes 'base' and 'exp' (exponent/power)
int power(int base, int exp){

    // Base case: any number to the power of 0 is 1
    if(exp == 0){
        return 1;
    }

    // Recursive step: multiply the base by the result of base^(exp-1)
    return base * power(base, exp - 1);
}

int main(){

    int b, n;
    
    cout << "Enter the base: ";
    cin >> b;
    
    cout << "Enter the power: ";
    cin >> n;

    // Call the function with both variables
    int result = power(b, n);
    
    cout << b << " raised to the power of " << n << " is: " << result << endl;

    return 0;
}