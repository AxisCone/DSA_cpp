#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int modelYear;
    int price;

   
    // Parameterized Constructor (3 parameters)
    Car(string brand, int modelYear, int price) {
        // Use of this keyword
        this->brand = brand;
        this->modelYear = modelYear;
        this->price = price;
    }

    // Copy Constructor(use '&' for reference)
    Car(Car &X){
        brand = X.brand;
        modelYear = X.modelYear;
        price = X.price;
    }

    // Function
    void Display() {
        cout << "Brand: " << brand << endl;
        cout << "Model Year: " << modelYear << endl;
        cout << "Price: " << price << endl << endl;
    }
};

int main() {
                      
    Car B("BMW", 2025, 7500000);  
    B.Display();

    Car C(B);        // calls copy constructor
    C.Display();

    Car D("Toyota", 2024 , 2000000);
    D.Display();

    Car E(D);       // calls copy constructor
    E.Display();


    return 0;
}