#include <iostream>
#include <iomanip>

using namespace std;

class GroceryItem {
private:
    // Private data members
    int stockNumber;
    double price;
    int quantityInStock;
    double totalValue;

    // Private helper functions
    void inputStockNumber() {
        do {
            cout << "enter stock number (1000 - 9999): ";
            cin >> stockNumber;
            if (stockNumber < 1000 || stockNumber > 9999) {
                cout << "INVALID ENTRY.";
            }
        } while (stockNumber < 1000 || stockNumber > 9999);
    }

    void inputPrice() {
        do {
            cout << "enter price: ";
            cin >> price;
            if (price < 0) {
                cout << "PRICE CANNOT BE NEGATIVE. ";
            }
        } while (price < 0);
    }

    void inputQuantity() {
        do {
            cout << "enter quantity in stock: ";
            cin >> quantityInStock;
            if (quantityInStock < 0) {
                cout << "QUANTITY CANNOT BE NEGATIVE. ";
            }
        } while (quantityInStock < 0);
    }

    void calculateTotalValue() {
        totalValue = price * quantityInStock;
    }

public:
    // Public function that coordinates the private helpers
    void dataEntry() {
        inputStockNumber();
        inputPrice();
        inputQuantity();
        calculateTotalValue();
    }

    // Public display function
    void displayItem() {
        cout << fixed << setprecision(2); // Format output for currency
        cout << "\n     grocery item details     " << endl;
        cout << "stock number: " << stockNumber << endl;
        cout << "price:        $" << price << endl;
        cout << "quantity:     " << quantityInStock << endl;
        cout << "total value:  $" << totalValue << endl;
        cout << "----------------------------" << endl;
    }
};

int main() {
    // 1. Create a GroceryItem object
    GroceryItem myItem;

    // 2. Assign values using the coordinated data entry function
    myItem.dataEntry();

    // 3. Display the item data
    myItem.displayItem();

    return 0;
}