#include <iostream>
using namespace std;

void print(int arr[], int index, int size) {
    if (index == size) return;

    cout << arr[index] << " ";
    print(arr, index + 1, size); 
}

int main() {
    int arr[6] = {12, 34, 56, 43, 78, 32};

    print(arr, 0, 6);

    return 0;
}