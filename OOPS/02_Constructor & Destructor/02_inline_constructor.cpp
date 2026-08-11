#include<iostream>
using namespace std;

class Human{
    public:
    string gender;
    int age;
    int IQ;
    
    // Default Constructor
    Human(){
        cout<<"Defualt constructor is called"<<endl;
        cout<<"Gender: "<<"Male"<<endl;
        cout<<"Age: "<<"24"<<endl;
        cout<<"IQ: "<<"108"<<endl<<endl;
    }

    //Inline Constructor Constructor (3 parameters)
    inline Human(string gender,int age,int IQ):gender(gender),age(age),IQ(IQ){
        
    }

     // Parameterized Constructor (2 parameters)
    Human(string gender,int age){
        this->gender = gender;
        this->age = age;
        IQ = 121;
    }

    // Function 
    void Display(){
        cout<<"Gender: "<<gender<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"IQ: "<<IQ<<endl<<endl;
    }

};

int main(){

    Human A; // calls default constructor

    Human B("Female",25,110);  // calls inline constructor(3 parameters)
    B.Display();

    Human C("Male",25);    // // calls parameterized constructor(2 parameters)
    C.Display();



}