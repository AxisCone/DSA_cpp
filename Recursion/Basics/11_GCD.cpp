#include <iostream>
using namespace std;

// Function to calculate Greatest Common Divisor (GCD) using Euclid's Algorithm
int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, (a % b));
}

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    if (cin >> num1 >> num2) {
        // Calculate GCD
        int result = GCD(num1, num2);
        
        cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    } else {
        cout << "Invalid input. Please enter valid integers." << endl;
    }

    return 0;
}