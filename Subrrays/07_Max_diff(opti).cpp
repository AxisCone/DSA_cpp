// Max Diff between two elements
// Optimised force approach
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

// Approach: What if I am on index[n] and I know greatest element from 
//           index[n+1] to index[last]

int max_diff(vector<int>& arr) {
    int n = arr.size();
    int ans = INT_MIN;
    int Suffix_max = arr.back();  //last element of array

    for(int i=arr.size()-2;i>=0;i--){
        ans = max(ans,Suffix_max-arr[i]);
        Suffix_max = max(Suffix_max,arr[i]);
    }
    
    return ans;
}

// Time Complexity : O(n)
// Space Complexity: O(1)

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