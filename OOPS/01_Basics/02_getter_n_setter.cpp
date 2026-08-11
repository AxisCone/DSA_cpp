#include <iostream>
using namespace std;

class Student {
private:
    // Data Members
    string name;
    int age;
    int roll_no;
    string grade;

public:
    
    // Setter Functions
    
    void set_name(string s) {
        if (s.empty()) {
            cout << "Invalid Name!\n";
            return;
        }
        name = s;
    }

    void set_age(int x) {
        if (x <= 0 || x >= 120) {
            cout << "Invalid Age!\n";
            return;
        }
        age = x;
    }

    void set_roll_no(int num) {
        roll_no = num;
    }

    void set_grade(string gra) {
        grade = gra;
    }

   
    // Getter Functions
  

    string get_name() {
        return name;
    }

    int get_age() {
        return age;
    }

    int get_roll_no() {
        return roll_no;
    }

    string get_grade() {
        int pin;
        cout<<"Enter the pin: ";
        cin>>pin;
        if (pin == 1234) {
            return grade;
        }
        return "Access Denied!";
    }

   

    // Display Function
    void display() {
       
        cout << "Name      : " << name << endl;
        cout << "Age       : " << age << " years" << endl;
        cout << "Roll No.  : " << roll_no << endl;
        cout << "Grade     : " << grade << endl;
    
    }
};

int main() {

    Student S1;

    // Setting Student Details
    S1.set_name("Lokesh Bisht");
    S1.set_age(19);
    S1.set_roll_no(57);
    S1.set_grade("A");

    // Display all details
    S1.display();

    // Using Getter Functions
    cout << "\nAccessing individual details:\n";
    cout << "Name  : " << S1.get_name() << endl;
    cout << "Age   : " << S1.get_age() << endl;
    cout << "Roll  : " << S1.get_roll_no() << endl;
    cout << "Grade : " << S1.get_grade() << endl;

    return 0;
}