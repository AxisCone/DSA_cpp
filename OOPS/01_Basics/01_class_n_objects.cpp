#include <iostream>
#include <vector>
using namespace std;

class Student {
public://with (public) access modifier,the attributes can be accessed outside   class Student
    string name;
    int age;
    int roll_no;
    string grade;
};

int main() {

    Student S1;

    S1.name = "Naman Tripathi";
    S1.age = 18;
    S1.roll_no = 48;
    S1.grade = "A+";

    Student S2;
    S2.name = "Prakash Nainwal";
    S2.age = 18;
    S2.roll_no = 53;
    S2.grade = "A+";


   
    cout << "Name      : " << S1.name << endl;
    cout << "Age       : " << S1.age << " years" << endl;
    cout << "Roll No.  : " << S1.roll_no << endl;
    cout << "Grade     : " << S1.grade << endl << endl;

    cout << "Name      : " << S2.name << endl;
    cout << "Age       : " << S2.age << " years" << endl;
    cout << "Roll No.  : " << S2.roll_no << endl;
    cout << "Grade     : " << S2.grade << endl;

    

    return 0;
}