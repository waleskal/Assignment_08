#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    int customerID;
    string lastName;
    string firstName;
    double creditLimit;

public:
    void setCustomerID(int id) {
        customerID = id;
    }

    void setLastName(string last) {
        lastName = last;
    }

    void setFirstName(string first) {
        firstName = first;
    }

    void setCreditLimit(double limit) {
        if (limit > 10000.00) {
            creditLimit = 10000.00;
        } else {
            creditLimit = limit;
        }
    }

    void displayCustomerInfo() {
        cout << "ID: " << customerID 
             << " | name: " << firstName << " " << lastName 
             << " | limit: $" << creditLimit << endl;
    }
};

int main() {
    // 1. Create an array of five Customer objects
    Customer customers[5];
    
    // Temporary variables for user input
    int tempID;
    string tempFirst, tempLast;
    double tempLimit;

    // 2. Prompt the user to enter values for each customer
    for (int i = 0; i < 5; i++) {
        cout << "\nentering data for Customer #" << (i + 1) << endl;
        
        cout << "enter Customer ID: ";
        cin >> tempID;
        customers[i].setCustomerID(tempID);

        cout << "enter first name: ";
        cin >> tempFirst;
        customers[i].setFirstName(tempFirst);

        cout << "enter last Nnme: ";
        cin >> tempLast;
        customers[i].setLastName(tempLast);

        cout << "enter credit limit: ";
        cin >> tempLimit;
        customers[i].setCreditLimit(tempLimit);
    }

    // 3. Display the information for all five customers
    cout << "\n" << "============================" << endl;
    cout << "      CUSTOMER DATABASE      " << endl;
    cout << "============================" << endl;
    
    for (int i = 0; i < 5; i++) {
        customers[i].displayCustomerInfo();
    }

    return 0;
}