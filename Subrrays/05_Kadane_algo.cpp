// Find the Largest Sum of a Contiguous Subarray using Kadane's Algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum subarray sum
int max_sum(vector<int>& arr) {
    int n = arr.size();

    int maximum = INT_MIN;   // Stores the maximum subarray sum found so far
    int sum = 0;             // Stores the current subarray sum

    // Traverse the array only once
    for (int i = 0; i < n; i++) {

        // Add the current element to the running sum
        sum += arr[i];

        // Update the maximum sum if the current subarray sum is larger
        maximum = max(sum, maximum);

        // If the running sum becomes negative,
        // discard it because it cannot contribute to a larger sum later
        if (sum < 0) {
            sum = 0;
        }
    }

    // Return the largest subarray sum
    return maximum;
}

int main() {
    int n;

    // Take the size of the vector as input
    cout << "Enter the size of vector: ";
    cin >> n;

    vector<int> arr(n);

    // Take vector elements as input
    cout << "Enter elements in vector: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the maximum contiguous subarray sum
    cout << "Largest sum in contiguous subarray: " << max_sum(arr);

    return 0;
}