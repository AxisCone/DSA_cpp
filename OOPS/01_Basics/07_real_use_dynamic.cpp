#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
};

int main() {
    int n = 3;

    // Create an array of 3 Student objects on the heap
    Student* students = new Student[n];

    // Store data
    students[0].name = "Amit";
    students[0].age = 20;

    students[1].name = "Rohit";
    students[1].age = 21;

    students[2].name = "Priya";
    students[2].age = 19;

    // Print data
    for (int i = 0; i < n; i++) {
        cout << students[i].name << " "
             << students[i].age << endl;
    }

    // Free memory
    delete[] students;

    return 0;
}