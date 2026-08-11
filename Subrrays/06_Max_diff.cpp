// Max Diff between two elements
// Brute force approach
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int max_diff(vector<int>& arr) {
    int n = arr.size();
    int ans = INT_MIN;

    for (int i = 0; i < n - 1; i++) {

        // Find the maximum element to the right of arr[i]
        int maximum = INT_MIN;

        for (int j = i + 1; j < n; j++) {
            maximum = max(maximum, arr[j]);
        }

        // Update the maximum difference
        ans = max(ans, maximum - arr[i]);
    }

    return ans;
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

    cout<<"Maximum diff betweem two elements: "<<max_diff(arr);

    return 0;
}