//You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.Return the index of the peak element.

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 1, end = arr.size() - 2, mid, ans;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            ans = mid;
            break;
        }
        else if (arr[mid] > arr[mid - 1]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {0, 2, 5, 7, 10, 8, 6, 3, 1};

    cout << "Mountain Array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    int peakIndex = peakIndexInMountainArray(arr);

    cout << "\nPeak Index: " << peakIndex;
    cout << "\nPeak Element: " << arr[peakIndex] << endl;

    return 0;
}

