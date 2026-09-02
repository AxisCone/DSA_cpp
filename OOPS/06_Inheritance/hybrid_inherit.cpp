
#include <iostream>
using namespace std;



//                    BASE CLASS


class Vehicle {
public:

    // Common properties of every vehicle
    string brand;
    string model;
    int year;

    // Constructor of Vehicle
    Vehicle(string brand, string model, int year) {

        // 'this->brand' refers to the class variable
        // 'brand' refers to the constructor parameter
        this->brand = brand;
        this->model = model;
        this->year = year;
    }

    // Function to display common vehicle information
    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};


// ======================================================
//                       CAR
// ======================================================

// 'virtual' inheritance is used here.
//
// Car inherits from Vehicle.
//
// The virtual keyword tells C++ that if another class
// inherits from both Car and another class that also
// inherits from Vehicle, only ONE Vehicle object should
// exist.
//
// This helps solve the DIAMOND PROBLEM.

class Car : virtual public Vehicle {
public:

    // Property specific to a normal car
    int engineCC;

    // Car constructor
    Car(string brand, string model, int year, int engineCC)
        : Vehicle(brand, model, year) {

        this->engineCC = engineCC;
    }

    // Function specific to Car
    void carFeature() {
        cout << "Engine: " << engineCC << " CC" << endl;
    }
};


// ======================================================
//                  ELECTRIC CAR
// ======================================================

// ElectricCar also virtually inherits Vehicle.
//
// Now both Car and ElectricCar share the SAME Vehicle
// object when HybridCar inherits from both.

class ElectricCar : virtual public Vehicle {
public:

    // Property specific to electric cars
    int batteryCapacity;

    // ElectricCar constructor
    ElectricCar(string brand, string model,
                int year, int batteryCapacity)
        : Vehicle(brand, model, year) {

        this->batteryCapacity = batteryCapacity;
    }

    // Function specific to ElectricCar
    void electricFeature() {
        cout << "Battery: "
             << batteryCapacity
             << " kWh" << endl;
    }
};


// ======================================================
//                    HYBRID CAR
// ======================================================

// HybridCar inherits from BOTH Car and ElectricCar.
//
// This is MULTIPLE INHERITANCE.
//
// Since Car and ElectricCar both inherit from Vehicle,
// the overall structure becomes:
//
//                    Vehicle
//                   /       \
//                  /         \
//                Car      ElectricCar
//                  \         /
//                   \       /
//                    HybridCar
//
// This is called the DIAMOND INHERITANCE structure.
//
// Virtual inheritance ensures that HybridCar contains
// only ONE Vehicle object.

class HybridCar : public Car, public ElectricCar {
public:

    // HybridCar constructor
    HybridCar(string brand,
              string model,
              int year,
              int engineCC,
              int batteryCapacity)

        // IMPORTANT:
        //
        // Because Vehicle is a VIRTUAL BASE CLASS,
        // the MOST DERIVED CLASS (HybridCar) is responsible
        // for constructing Vehicle.
        //
        // Therefore, Vehicle is explicitly called here.

        : Vehicle(brand, model, year),

          // Construct the Car part
          Car(brand, model, year, engineCC),

          // Construct the ElectricCar part
          ElectricCar(brand, model, year, batteryCapacity) {

    }


    // Display all information about the HybridCar
    void display() {

        // Function inherited from Vehicle
        displayVehicle();

        // Function inherited from Car
        carFeature();

        // Function inherited from ElectricCar
        electricFeature();
    }
};


// ======================================================
//                       MAIN
// ======================================================

int main() {

    // Creating a HybridCar object
    //
    // Brand           = Toyota
    // Model           = Prius
    // Year            = 2024
    // Engine          = 1798 CC
    // Battery         = 8 kWh

    HybridCar H1(
        "Toyota",
        "Prius",
        2024,
        1798,
        8
    );


    // Display all information
    H1.display();


    return 0;
}
