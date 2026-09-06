#include <iostream>
using namespace std;

// Function to calculate the number of distinct ways to climb n stairs
int climbStairs(int n) {
    if (n <= 1) return 1;

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int totalWays = climbStairs(n);
    cout << "Number of distinct ways to reach the top: " << totalWays << endl;

    return 0;
}