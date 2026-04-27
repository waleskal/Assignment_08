#include <iostream>
#include <iomanip>

using namespace std;

class GroceryItem {
private:
    int stockNumber;
    double price;
    int quantityInStock;
    double totalValue;

    // Private helper functions for internal logic
    void inputStockNumber() {
        do {
            cout << "enter stock number (1000 - 9999): ";
            cin >> stockNumber;
            if (stockNumber < 1000 || stockNumber > 9999) {
                cout << "INVALID. ";
            }
        } while (stockNumber < 1000 || stockNumber > 9999);
    }

    void inputPrice() {
        do {
            cout << "enter price: ";
            cin >> price;
        } while (price < 0);
    }

    void inputQuantity() {
        do {
            cout << "enter quantity: ";
            cin >> quantityInStock;
        } while (quantityInStock < 0);
    }

    void calculateTotalValue() {
        totalValue = price * quantityInStock;
    }

public:
    // Public interface to trigger data entry
    void dataEntry() {
        inputStockNumber();
        inputPrice();
        inputQuantity();
        calculateTotalValue();
    }

    // Public display function
    void displayItem() {
        cout << left << setw(15) << stockNumber 
             << "$" << setw(10) << price 
             << setw(10) << quantityInStock 
             << "$" << totalValue << endl;
    }
};

int main() {
    // 1. Create an array of 10 GroceryItem objects
    GroceryItem inventory[10];

    // 2. Assign values to each object using a loop
    for (int i = 0; i < 10; i++) {
        cout << "\n     data entry for item " << (i + 1) << " ---" << endl;
        inventory[i].dataEntry();
    }

    // 3. Display the information for all items
    cout << fixed << setprecision(2);
    cout << "\n==============================================" << endl;
    cout << left << setw(15) << "stock #" 
         << setw(11) << "price" 
         << setw(10) << "qty" 
         << "total value" << endl;
    cout << "----------------------------------------------" << endl;

    for (int i = 0; i < 10; i++) {
        inventory[i].displayItem();
    }
    cout << "==============================================" << endl;

    return 0;
}