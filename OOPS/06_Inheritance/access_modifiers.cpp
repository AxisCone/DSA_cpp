#include <iostream>
using namespace std;


// ===================== BASE CLASS =====================

class Human {

private:
    // PRIVATE members can only be accessed inside the Human class.
    // Even the child classes (Hardware_Engineer and Software_Engineer)
    // cannot directly access these variables.
    string religion;
    string skin_color;


protected:
    // PROTECTED members can be accessed:
    // 1. Inside the Human class
    // 2. Inside classes that inherit from Human
    //
    // Therefore, Hardware_Engineer and Software_Engineer
    // can directly use name, id, age and experience.
    string name;
    int id;
    int age;
    float experience;


public:

    // Constructor of Human class
    //
    // This constructor is responsible for initializing
    // the data members of the Human part of the object.
    Human(string name, int id, int age, float experience,
          string religion, string skin_color) {

        this->name = name;
        this->id = id;
        this->age = age;
        this->experience = experience;
        this->religion = religion;
        this->skin_color = skin_color;
    }


    // PUBLIC function
    //
    // It can be called from:
    // 1. Human class
    // 2. Child classes
    // 3. main()
    void showBasicDetails() {

        cout << "Name       : " << name << endl;
        cout << "ID         : " << id << endl;
        cout << "Age        : " << age << endl;
        cout << "Experience : " << experience << " years" << endl;
    }
};



// ================= HARDWARE ENGINEER =================

// Hardware_Engineer INHERITS from Human.
//
// "public Human" means:
// Hardware_Engineer is a child/derived class of Human.
//
// Hardware_Engineer automatically gets the accessible
// members of Human.
class Hardware_Engineer : public Human {

private:

    // These are specific to Hardware_Engineer.
    // They are not part of the Human class.
    int salary;
    string hardwareDomain;


public:

    // Constructor of Hardware_Engineer
    //
    // It receives values for both:
    // 1. Human's data
    // 2. Hardware_Engineer's own data
    Hardware_Engineer(string name, int id, int age,
                      float experience, string religion,
                      string skin_color, int salary,
                      string hardwareDomain)


        // CONSTRUCTOR INITIALIZER LIST
        //
        // Hardware_Engineer inherits from Human.
        //
        // Therefore, before constructing the Hardware_Engineer
        // part, we need to construct the Human part.
        //
        // This calls the Human constructor and passes
        // the required values to it.
        //
        // This is NOT inheritance.
        // Inheritance was already done here:
        //
        // class Hardware_Engineer : public Human
        //
        : Human(name, id, age, experience, religion, skin_color) {


        // These two variables belong to Hardware_Engineer,
        // so they are initialized inside this constructor body.
        this->salary = salary;
        this->hardwareDomain = hardwareDomain;
    }


    // Function specific to Hardware_Engineer
    void display() {

        cout << "\n===== HARDWARE ENGINEER =====" << endl;


        // showBasicDetails() belongs to Human.
        //
        // Since Hardware_Engineer inherits from Human,
        // it can use this public function.
        showBasicDetails();


        // hardwareDomain is PRIVATE inside Hardware_Engineer,
        // but we can access it here because we are inside
        // the Hardware_Engineer class.
        cout << "Domain     : " << hardwareDomain << endl;

        cout << "Salary     : " << salary << endl;
    }


    // Function representing the work of a Hardware Engineer
    void work() {

        // name is PROTECTED in Human.
        //
        // Since Hardware_Engineer inherits from Human,
        // it can directly access name.
        cout << name << " is working on "
             << hardwareDomain << "." << endl;
    }
};



// ================= SOFTWARE ENGINEER =================

// Software_Engineer is also a child class of Human.
//
// Therefore:
//
//              Human
//             /     \
//            /       \
// Hardware_Engineer  Software_Engineer
//
class Software_Engineer : public Human {

private:

    // These variables are specific to Software_Engineer.
    int salary;
    string programmingLanguage;


public:

    // Constructor of Software_Engineer
    Software_Engineer(string name, int id, int age,
                      float experience, string religion,
                      string skin_color, int salary,
                      string programmingLanguage)


        // Again, we first initialize the Human part
        // by calling the Human constructor.
        //
        // Human's constructor receives:
        // name, id, age, experience, religion, skin_color
        //
        : Human(name, id, age, experience, religion, skin_color) {


        // These belong to Software_Engineer,
        // so they are initialized here.
        this->salary = salary;
        this->programmingLanguage = programmingLanguage;
    }


    // Function specific to Software_Engineer
    void display() {

        cout << "\n===== SOFTWARE ENGINEER =====" << endl;


        // showBasicDetails() comes from Human.
        // Software_Engineer can use it because it inherits Human.
        showBasicDetails();


        // These are private members of Software_Engineer,
        // but we are inside the class, so we can access them.
        cout << "Language   : " << programmingLanguage << endl;
        cout << "Salary     : " << salary << endl;
    }


    // Function representing the work of a Software Engineer
    void work() {

        // name is protected in Human.
        // Therefore, Software_Engineer can access it.
        cout << name << " is developing software using "
             << programmingLanguage << "." << endl;
    }
};



// ========================= MAIN =========================

int main() {


    // Creating an object of Hardware_Engineer.
    //
    // The arguments are passed to the Hardware_Engineer constructor.
    Hardware_Engineer hardware(
        "Himanshu Tyagi",
        2601001,
        26,
        4.5,
        "Religion",
        "Skin Color",
        125000,
        "Embedded Systems"
    );


    // Creating an object of Software_Engineer.
    //
    // Again, the arguments are passed to the
    // Software_Engineer constructor.
    Software_Engineer software(
        "Rahul Sharma",
        2601002,
        24,
        2.5,
        "Religion",
        "Skin Color",
        100000,
        "C++"
    );


    // Calling Hardware_Engineer's display() function.
    hardware.display();

    // Calling Hardware_Engineer's work() function.
    hardware.work();


    // Calling Software_Engineer's display() function.
    software.display();

    // Calling Software_Engineer's work() function.
    software.work();


    return 0;
}