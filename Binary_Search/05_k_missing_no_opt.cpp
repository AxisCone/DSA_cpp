#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {    
    int n = arr.size();
    int start = 0, end = n - 1;
    int ans = n;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] - mid - 1 >= k) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans + k;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << "\nK = " << k;
    cout << "\nThe " << k << "th missing positive number is: "
         << findKthPositive(arr, k) << endl;

    return 0;
}