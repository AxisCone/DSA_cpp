/*
    DEMO: ENCAPSULATION
    ---------------------------------------------------------
    Encapsulation = bundling data (name, acc_no, balance, age) together
    with the functions that operate on it (deposit, withdraw, ...),
    while HIDING the raw data from the outside world.

    How it's done here:
      1. All data members are declared under "private" (the default
         section of a class, before "public:") -> code outside the
         class CANNOT do things like "A1.balance = -5000;" directly.
         The compiler simply won't allow it.

      2. The ONLY way to read or change that data is through the
         public functions we choose to expose (deposit, withdraw,
         update_age, get_balance, ...). This is the class's
         "controlled interface" to its own data.

      3. Because every change goes through a function, we can add
         VALIDATION there (amount > 0, age within a sane range, etc.)
         This is the real payoff of encapsulation: it protects the
         object from ending up in an invalid/nonsensical state
         (e.g. negative balance, age of 300) - something that would
         be impossible to stop if outside code could edit the
         variables directly.

    In short: private data + public controlled access = encapsulation.
*/

#include <iostream>
using namespace std;

class Customer {

    // ---- Private data: hidden from outside the class ----
    // No code outside Customer can read or write these directly.
    // e.g. "A1.balance = 99999;" in main() would fail to compile.
    string name;
    int acc_no;
    int balance;
    int age;

public:

    // Constructor: the only way to set the INITIAL state of a new object.
    Customer(string name, int acc_no, int balance, int age) {
        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;
        this->age = age;
    }

    // ---- Controlled way to modify balance (part of the public interface) ----
    // Outside code can never set balance directly; it must go through
    // deposit()/withdraw(), which enforce the rules below.
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    // ---- Controlled way to modify age ----
    // Encapsulation in action: the class refuses to accept an
    // unrealistic age, protecting its own internal data from misuse -
    // something a plain public "age" variable could never enforce.
    void update_age(int age) {
        if (age > 18 && age < 150) {
            this->age = age;
        }
    }

    // ---- Read-only access (getters) ----
    // Since the data is private, we expose small "read-only windows"
    // for code outside the class that just wants to KNOW a value,
    // without being able to change it. "const" here promises this
    // function won't modify the object.
    int get_balance() const {
        return balance;
    }

    int get_age() const {
        return age;
    }

    // Print the full state - the usual way outside code observes
    // an object without needing direct access to its private data.
    void display() const {
        cout << name << " " << acc_no << " " << balance << " " << age << endl;
    }
};

int main() {

    Customer A1("Mark", 123, 25000, 24);
    Customer A2("Robin", 574, 18000, 26);
    Customer A3("Adam", 674, 35000, 28);

    // A1.balance = 999999;   // <-- would NOT compile: balance is private.
    // This line is commented out on purpose - it's the whole point of
    // encapsulation. All changes MUST go through the public functions below.

    A1.update_age(26);   // valid update, goes through the validated setter
    A1.display();

    // Reading a private value safely, via a getter:
    cout << "A1's balance via getter: " << A1.get_balance() << endl;

    return 0;
}