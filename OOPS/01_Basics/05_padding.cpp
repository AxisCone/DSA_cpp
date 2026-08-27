#include <iostream>
using namespace std;

// ==================== Example 1 ====================
class A
{
    char c;   // 1 byte
    int b;    // 4 bytes
    char d;   // 1 byte

    // Memory layout:
    // c  p  p  p  b  b  b  b  d  p  p  p
    // Total = 12 bytes
};


// ==================== Example 2 ====================
class B
{
    char c;   // 1 byte
    char d;   // 1 byte
    int b;    // 4 bytes

    // Memory layout:
    // c  d  p  p  b  b  b  b
    // Total = 8 bytes
};


// ==================== Example 3 ====================
class C
{
    char c;     // 1 byte
    char d;     // 1 byte
    int b;      // 4 bytes
    double e;   // 8 bytes

    // Memory layout:
    // c  d  b  b  b  b  p  p  e  e  e  e  e  e  e  e
    // Total = 16 bytes
};


// ==================== Example 4 ====================
class D
{
    char c;     // 1 byte
    int b;      // 4 bytes
    char d;     // 1 byte
    double e;   // 8 bytes

    // Memory layout:
    // c  p  p  p  b  b  b  b  d  p  p  p  e e e e e e e e
    // Total = 24 bytes
};


int main()
{
    A obj1;
    B obj2;
    C obj3;
    D obj4;

    cout << "Example 1: " << sizeof(obj1) << " bytes" << endl;
    cout << "Example 2: " << sizeof(obj2) << " bytes" << endl;
    cout << "Example 3: " << sizeof(obj3) << " bytes" << endl;
    cout << "Example 4: " << sizeof(obj4) << " bytes" << endl;

    return 0;
}