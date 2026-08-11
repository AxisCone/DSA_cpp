// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    int ans = nums.size();

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            ans = mid;
            return ans;
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            ans = mid;
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,4,6,8,10,14,16,18};
    int target = 10;

    int result = searchInsert(nums, target);

    cout << result << endl;

    return 0;
}