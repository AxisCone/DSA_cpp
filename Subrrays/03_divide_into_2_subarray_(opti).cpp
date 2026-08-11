#include <iostream>
#include <vector>
using namespace std;

bool equalSubarraySum(vector<int> &arr) {
    int n = arr.size();

    // First pass: Calculate the sum of the entire array.
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    int sum1 = 0;

    // Second pass: Try every possible partition.
    for (int i = 0; i < n - 1; i++) {

        // Keep adding elements to the left subarray.
        sum1 += arr[i];

        /*
         * Optimization:
         * Instead of using another loop to calculate the right subarray sum,
         * we use:
         *
         *      rightSum = total_sum - sum1
         *
         * because:
         * total_sum = leftSum + rightSum
         *
         * Therefore,
         * rightSum = total_sum - leftSum
         *
         * This avoids recalculating the right subarray sum every time,
         * reducing the time complexity from O(n²) to O(n).
         */
        if (sum1 == (total_sum - sum1)) {
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