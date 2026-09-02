#include <iostream>
using namespace std;

// ================= VEHICLE =================

class Vehicle {
public:
    string brand;
    string model;
    int year;

    Vehicle(string brand, string model, int year) {
        this->brand = brand;
        this->model = model;
        this->year = year;
    }

    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};


// ================= CAR =================

class Car : public Vehicle {
public:
    string fuelType;

    Car(string brand, string model, int year, string fuelType)
        : Vehicle(brand, model, year) {
        this->fuelType = fuelType;
    }

    void display() {
        displayVehicle();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Vehicle Type: Car" << endl;
        cout << "------------------------" << endl;
    }
};


// ================= ELECTRIC CAR =================

class ElectricCar : public Vehicle {
public:
    int batteryCapacity;

    ElectricCar(string brand, string model, int year, int batteryCapacity)
        : Vehicle(brand, model, year) {
        this->batteryCapacity = batteryCapacity;
    }

    void display() {
        displayVehicle();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Vehicle Type: Electric Car" << endl;
        cout << "------------------------" << endl;
    }
};


// ================= MOTORCYCLE =================

class Motorcycle : public Vehicle {
public:
    int engineCC;

    Motorcycle(string brand, string model, int year, int engineCC)
        : Vehicle(brand, model, year) {
        this->engineCC = engineCC;
    }

    void display() {
        displayVehicle();
        cout << "Engine: " << engineCC << " CC" << endl;
        cout << "Vehicle Type: Motorcycle" << endl;
        cout << "------------------------" << endl;
    }
};


// ================= MAIN =================

int main() {

    Car C1("Toyota", "Camry", 2024, "Petrol");
    Car C2("Honda", "City", 2023, "Petrol");

    ElectricCar E1("Tesla", "Model 3", 2024, 75);
    ElectricCar E2("Tata", "Nexon EV", 2023, 40);

    Motorcycle M1("Yamaha", "R15", 2024, 155);
    Motorcycle M2("Royal Enfield", "Classic 350", 2023, 349);


    C1.display();
    C2.display();

    E1.display();
    E2.display();

    M1.display();
    M2.display();

    return 0;
}

