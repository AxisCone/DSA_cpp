#include<iostream>
#include<vector>
using namespace std;

class Animal{
    public:

    // by using (virtual) the functions of its child will compile in (RUNTIME)

    // 'virtual' tells the compiler: "don't decide which sound() to call
    // at compile time based on pointer type — decide at RUNTIME based on
    // the actual object being pointed to." This enables dynamic binding.
    virtual void sound(){  
        cout<<"Huh-Huh"<<endl;
    }
};

class Dog:public Animal{
    public:
    // this OVERRIDES Animal::sound() because sound() is virtual in the base class.
    // Dog inherits the virtual-ness automatically (no need to write 'virtual' again,
    // though some style guides recommend adding 'override' here for clarity)
    void sound(){
        cout<<"Bark"<<endl;
    }
};

class Cat:public Animal{
    public:
    // same idea — this overrides the base class version for Cat objects
    void sound(){
        cout<<"Meow"<<endl;
    }
};


int main(){

// p is declared as a pointer to Animal (its STATIC type is Animal*)
Animal* p;

// but p is made to point to a Dog object on the heap
// (its DYNAMIC/actual type at runtime is Dog)
p = new Dog();

// even though p's declared type is Animal*, virtual dispatch looks at
// the ACTUAL object p points to (a Dog) and calls Dog::sound() instead
// of Animal::sound(). This is why "Bark" prints, not "Huh-Huh".
p->sound();


// a vector of Animal* can hold pointers to ANY class derived from Animal
// (Dog, Cat, or future classes like Bird) — this is possible because
// a derived class pointer can always be stored in a base class pointer
vector<Animal*>animals;
    animals.push_back(new Dog());   // stores a Dog, but as an Animal*
    animals.push_back(new Cat());   // stores a Cat, but as an Animal*
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    // looping through the vector by index
    for(int i=0;i<animals.size();i++){

        // p's declared type stays Animal* the whole time,
        // but on each iteration it points to a DIFFERENT actual object
        p = animals[i];

        // this is the key line: because sound() is virtual, the program
        // checks what object p ACTUALLY points to at this exact moment
        // (Dog or Cat) and calls that class's version of sound().
        // Without 'virtual', this would call Animal::sound() every time,
        // printing "Huh-Huh" four times regardless of the real object type.
        p->sound();
    }

    // NOTE: not shown here, but in real code you should also do:
    // for(int i = 0; i < animals.size(); i++) delete animals[i];
    // to free the memory allocated by 'new' and avoid memory leaks.

}