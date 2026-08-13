#include<iostream>
using namespace std;

class Human{
    
    private:  // don't wanna know these two attributes
    string religion;
    string skin_color;

    protected:  // so can't be directly accessed outside class, 
                //but can be inherited
    string name;
    int id;
    int age;
    float exp;   
};

class Hardware_Engineer:protected Human{

    private:
    int salary;

    public:

    Hardware_Engineer(){

    }

    Hardware_Engineer(string name,int id,int age,float exp,int salary){
        this->name = name;
        this->id = id;
        this->age = age;
        this->exp = exp;
        this->salary = salary;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Exp: "<<exp<<endl;
        cout<<"salary: "<<salary<<endl;

    }

};



int main(){

    Hardware_Engineer A("Himanshu Tyagi",2601001,26,4.5,125000);
    A.display();
    

}