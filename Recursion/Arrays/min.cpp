#include <iostream>
#include <algorithm> // Required for std::min

using namespace std;

int min_in_array(int arr[], int index, int size) {
    // Base case: if we are at the last element, return it.
    if (index == size - 1) {
        return arr[index];
    }

    // Recursive step: return the minimum of the current element 
    // and the minimum of the rest of the array.
    return min(arr[index], min_in_array(arr, index + 1, size));
}

int main() {
    int arr[6] = {12, 34, 56, 43, 78, 32};

    int smallest = min_in_array(arr, 0, 6);
    
    cout << "The smallest element is: " << smallest << endl;
   
    return 0;
}