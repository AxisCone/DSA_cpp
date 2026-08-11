#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int max_sum(vector<int>& arr){
    int n = arr.size();

    int maximum = INT_MIN;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maximum = max(sum,maximum);

        }
    }

        return maximum;
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

    cout<<"Largest sum in contiguos subarray: "<<max_sum(arr);

    return 0;
}