#include<iostream>
using namespace std;

class vehicle{
    protected:
    string Engine_no;
    string software_code;
    
    public:
    string type;
    string model;
    float price;
};

class car:public vehicle{
    private:
    string OBD_2_protocol;
    float windshield_bond_strength;

    public:
    car(string Engine_no,string software_code, string type, string model,float price, string OBD_2_protocol, float windshield_bond_strength){

        this->Engine_no = Engine_no;
        this->software_code = software_code;
        this->type = type;
        this->model = model;
        this->price = price;
        this->OBD_2_protocol = OBD_2_protocol;
        this->windshield_bond_strength = windshield_bond_strength;

    }

    void display() {
    cout << "\n========== CAR DETAILS ==========" << endl;
    cout << "Engine No.              : " << Engine_no << endl;
    cout << "Software Code           : " << software_code << endl;
    cout << "Type                    : " << type << endl;
    cout << "Model                   : " << model << endl;
    cout << "Price                   : " << price << endl;
    cout << "OBD-II Protocol         : " << OBD_2_protocol << endl;
    cout << "Windshield Bond Strength: "
         << windshield_bond_strength << endl;
}


};

int main() {
    car c(
        "ENG12345",
        "SW2026",
        "SUV",
        "Mahindra XUV700",
        1800000,
        "CAN",
        5.5
    );

    c.display();

    return 0;
}