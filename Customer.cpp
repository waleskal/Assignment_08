#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    // Private data members
    int customerID;
    string lastName;
    string firstName;
    double creditLimit;

public:
    // Public functions to set each field individually
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
        // Requirement: The credit limit cannot exceed $10,000
        if (limit > 10000.00) {
            creditLimit = 10000.00;
        } else if (limit < 0) {
            creditLimit = 0; // Ensures limit isn't negative
        } else {
            creditLimit = limit;
        }
    }

    // Function that displays all customer information
    void displayCustomerInfo() {
        cout << "\n customer record " << endl;
        cout << "customer ID:  " << customerID << endl;
        cout << "name:         " << firstName << " " << lastName << endl;
        cout << "credit limit: $" << creditLimit << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    // 1. Create one Customer object
    Customer myCustomer;

    // 2. Assign values to the fields
    myCustomer.setCustomerID(5521);
    myCustomer.setFirstName("Jordan");
    myCustomer.setLastName("Rivers");
    
    // Testing the logic: Setting it to $12,000 should result in $10,000
    myCustomer.setCreditLimit(12000.00);

    // 3. Display the customer data
    myCustomer.displayCustomerInfo();

    return 0;
}