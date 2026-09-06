#include <iostream>
using namespace std;

int sum(const int arr[], int index) {
    // Base Case: when index reaches 0, return the first element
    if (index == 0) return arr[0];

    // Current element + sum of remaining elements to the left
    return arr[index] + sum(arr, index - 1);
}

int main() {
    int arr[6] = {12, 34, 56, 43, 78, 32};

    int ans = sum(arr, 5); // Pass last index (5)
    cout << ans << endl;   // Output: 255

    return 0;
}