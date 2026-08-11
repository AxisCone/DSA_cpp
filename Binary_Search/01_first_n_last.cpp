// Find First and last occurence of an element 

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    int first = -1, last = -1;

    // Find First Occurrence
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            first = mid;
            end = mid - 1;      // Search on the left side
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    // Find Last Occurrence
    start = 0;
    end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            last = mid;
            start = mid + 1;    // Search on the right side
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    vector<int> position(2);
    position[0] = first;
    position[1] = last;

    return position;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}