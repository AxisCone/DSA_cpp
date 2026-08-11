#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int i = 0;              // Pointer for the array
    int current = 1;        // Current positive number to check
    int missingCount = 0;

    while (true) {
        if (i < arr.size() && arr[i] == current) {
            // Number exists in the array
            i++;
        } else {
            // Number is missing
            missingCount++;

            if (missingCount == k) {
                return current;
            }
        }

        current++;
    }
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << findKthPositive(arr, k);
    return 0;
}