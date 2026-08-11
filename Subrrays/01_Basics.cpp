#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the size of the subarray: ";
    cin >> k;

    if (k > n || k <= 0) {
        cout << "Invalid subarray size!" << endl;
        return 0;
    }

    cout << "\nSubarrays of size " << k << " are:\n";

    for (int i = 0; i <= n - k; i++) {
        for (int j = i; j < i + k; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}