#include <iostream>

// The function takes the array, its size, and the current index (defaults to 0)
int countEvens(int arr[], int size, int index = 0) {
    // Base case: if the index reaches the size of the array, we are done
    if (index == size) {
        return 0;
    }
    
    // Check if the current element is even (1 if true, 0 if false)
    int isEven = (arr[index] % 2 == 0) ? 1 : 0;
    
    // Add current result and make the recursive call for the next index
    return isEven + countEvens(arr, size, index + 1);
}

int main() {
    // Example usage
    int myArray[] = {1, 2, 3, 4, 5, 6, 8};
    
    // Calculate the size of the array
    int size = sizeof(myArray) / sizeof(myArray[0]);
    
    int result = countEvens(myArray, size);
    std::cout << "Number of even elements: " << result << std::endl; // Output: 4
    
    return 0;
}