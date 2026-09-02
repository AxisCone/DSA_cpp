#include <iostream>
using namespace std;

class Computer {
public:
    string processor;
    int ram;
};

class Battery {
public:
    int batteryCapacity;
    float backup;
};

class Laptop : public Computer, public Battery {
private:
    string brand;
    string model;
    float price;

public:

    Laptop(string processor, int ram,
           int batteryCapacity, float backup,
           string brand, string model, float price) {

        this->processor = processor;
        this->ram = ram;
        this->batteryCapacity = batteryCapacity;
        this->backup = backup;
        this->brand = brand;
        this->model = model;
        this->price = price;
    }

    void display() {
        cout << "\n========== LAPTOP DETAILS ==========" << endl;
        cout << "Brand             : " << brand << endl;
        cout << "Model             : " << model << endl;
        cout << "Processor         : " << processor << endl;
        cout << "RAM               : " << ram << " GB" << endl;
        cout << "Battery Capacity  : " << batteryCapacity << " Wh" << endl;
        cout << "Battery Backup    : " << backup << " hours" << endl;
        cout << "Price             : " << price << endl;
    }
};

int main() {

    Laptop l(
        "Intel Core i7",
        16,
        70,
        8.5,
        "Lenovo",
        "IdeaPad Slim 5",
        75000
    );

    l.display();

    return 0;
}