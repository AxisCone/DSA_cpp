/*
    DEMO: STATIC DATA MEMBERS & STATIC MEMBER FUNCTIONS
    ----------------------------------------------------
    Goal: Track bank-wide info (total customers, total money in bank)
    that is SHARED across all Customer objects, instead of being
    duplicated inside each object.

    Key idea:
      - Normal (non-static) data members -> each object gets its OWN copy.
        e.g. name, acc_no, balance -> different for Mark vs Robin.

      - Static data members -> only ONE copy exists, shared by the
        whole class. All objects read/write the SAME variable.
        e.g. total_customer, total_balance -> same value seen by
        every object, and it updates whenever ANY object changes it.

      - Static member functions -> can be called using the CLASS name
        (Customer::accestatic()) without needing any object. They can
        only access static data directly (no "this" pointer exists
        for them, since they don't belong to one specific object).
*/

#include <iostream>
using namespace std;

class Customer {

    // ---------- Per-object data (each Customer has its own) ----------
    string name;
    int acc_no;
    int balance;

    // ---------- Shared/class-wide data (ONE copy for all objects) ----------
    static int total_customer; // increases every time a new Customer is created
    static int total_balance;  // sum of every customer's balance, kept in sync

public:

    // Constructor: runs once per object creation.
    // Every time a new Customer is made, we also update the
    // shared static counters -> that's what keeps them "bank-wide".
    Customer(string name, int acc_no, int balance) {
        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;

        total_customer++;        // one more customer now exists
        total_balance += balance; // their opening balance joins the bank total
    }

    // Deposit money into THIS customer's account.
    // Also updates the bank-wide total, since the bank's total
    // money changes whenever any single account changes.
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            total_balance += amount;
        }
    }

    // Withdraw money from THIS customer's account (only if funds allow).
    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            total_balance -= amount;
        }
    }

    // STATIC function: belongs to the class, not to any one object.
    // Called as Customer::accestatic() -- notice we never need an
    // object to call it, and it can only touch static members
    // (total_customer, total_balance), never name/acc_no/balance
    // of a specific customer.
    static void accestatic() {
        cout << "Total number of customers: " << total_customer << endl;
        cout << "Total money in bank      : " << total_balance << endl;
    }

    // Non-static function: needs an actual object to call it (e.g. A1.display()),
    // because it prints that object's own name/acc_no/balance.
    // It CAN still read static members (total_customer) since static
    // data is visible to every object too.
    void display() {
        cout << name << " " << acc_no << " " << balance
             << " | total_customer so far: " << total_customer << endl;
    }
};

// ---------------------------------------------------------------------
// Static data members MUST be defined (given storage) outside the class,
// exactly once, in the .cpp file. Declaring them inside the class only
// says "this exists"; this line is what actually creates the variable.
// ---------------------------------------------------------------------
int Customer::total_customer = 0;
int Customer::total_balance = 0;

int main() {

    // Creating two objects -> constructor runs twice ->
    // total_customer becomes 2, total_balance becomes 25000+15000.
    Customer A1("Mark", 123, 25000);
    Customer A2("Robin", 574, 15000);

    cout << "-- After creating 2 customers --" << endl;
    Customer::accestatic(); // called via class name, no object needed

    // These change ONE customer's balance, but since total_balance
    // is static/shared, the class-wide total reflects it too.
    A1.deposit(4500);
    A2.withdraw(6000);

    cout << "\n-- After deposit/withdraw --" << endl;
    Customer::accestatic();

    cout << "\n-- Individual customer details --" << endl;
    A1.display();
    A2.display();

    return 0;
}