#include <iostream>  // Provides cout and other input/output functions
#include <new>       // Provides std::bad_alloc for handling memory allocation failure

using namespace std;

// A class that manages a dynamically allocated array
class MyArray {

    int* arr;  // Pointer that will store the address of the dynamically allocated array

public:

    // Constructor
    // It is automatically called when an object of MyArray is created
    MyArray(int size) {

        cout << "Constructor: Trying to allocate memory...\n";

        // Try to allocate memory for 'size' integers
        //
        // If enough memory is available:
        //     Memory is allocated and its address is stored in arr
        //
        // If memory is NOT available:
        //     new throws a std::bad_alloc exception
        //     The object is NOT successfully created
        arr = new int[size];

        cout << "Memory allocated successfully!\n";
    }

    // Normal member function
    void work() {

        cout << "Doing some work...\n";
    }

    // Destructor
    // Automatically called when the object is destroyed
    ~MyArray() {

        // Release the memory that was allocated using new[]
        delete[] arr;

        cout << "Memory released.\n";
    }
};


int main() {

    cout << "Before object creation\n";

    // Create an object of MyArray
    //
    // This first calls the constructor:
    //     MyArray(int size)
    //
    // The constructor tries to allocate memory for
    // 1,000,000,000 integers.
    //
    // If memory allocation succeeds:
    //     obj is created
    //     The code below continues normally.
    //
    // If memory allocation fails:
    //     new throws std::bad_alloc
    //     obj is NOT created
    //     The code after this line is NOT executed
    MyArray obj(10);

    cout << "Object created\n";

    // This function can only be called if
    // the object was successfully created.
    obj.work();

    cout << "Remaining code executes\n";

    return 0;

    // When main() ends, obj is destroyed.
    // Therefore, the destructor ~MyArray() is automatically called.
}