#include <iostream>
#include <vector>
using namespace std;

bool equalSubarraySum(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int sum1 = 0;
        int sum2 = 0;

        // Left subarray
        for (int j = 0; j <= i; j++) {
            sum1 += arr[j];
        }

        // Right subarray
        for (int j = i + 1; j < n; j++) {
            sum2 += arr[j];
        }

        if (sum1 == sum2) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements in vector: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (equalSubarraySum(arr)) {
        cout << "Array can be divided into two subarrays with equal sum.";
    } else {
        cout << "Array cannot be divided into two subarrays with equal sum.";
    }

    return 0;
}