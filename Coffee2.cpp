#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CoffeeOrder {
private:
    static const double COFFEE_PRICE;
    int cream;
    int milk;
    int sugar;
    int sweetener;

public:
    
    static double getPrice() { return COFFEE_PRICE; }

    void setOrder() {
        cout << "enter 1 for Yes, 0 for No:" << endl;
        
        cout << "  cream? ";
        cin >> cream;
        cout << "  milk? ";
        cin >> milk;
        cout << "  sugar? ";
        cin >> sugar;
        cout << "  artificial sweetener? ";
        cin >> sweetener;


        if (milk == 1 && cream == 1) {
            milk = 0;
            cout << "  * Logic: Defaulting to cream only." << endl;
        }
        if (sugar == 1 && sweetener == 1) {
            sweetener = 0;
            cout << "  * Logic: Defaulting to sugar only." << endl;
        }
    }

    void displayOrder(int orderNum) {
        cout << "order #" << orderNum << ": ";
        cout << "[cream: " << (cream ? "Y" : "N") << "] ";
        cout << "[milk: " << (milk ? "Y" : "N") << "] ";
        cout << "[sugar: " << (sugar ? "Y" : "N") << "] ";
        cout << "[sweetener: " << (sweetener ? "Y" : "N") << "]" << endl;
    }
};

const double CoffeeOrder::COFFEE_PRICE = 1.25;

int main() {
    const int MAX_ORDERS = 10;
    CoffeeOrder orders[MAX_ORDERS];
    int count = 0;
    char choice;


    do {
        cout << "\n    entering coffee order " << (count + 1) << " ---" << endl;
        orders[count].setOrder();
        count++;

        if (count < MAX_ORDERS) {
            cout << "add another coffee? (y/n): ";
            cin >> choice;
        } else {
            cout << "\nmaximum of 10 orders reached." << endl;
            choice = 'n';
        }

    } while (count < MAX_ORDERS && (choice == 'y' || choice == 'Y'));

    cout << "\n===============================" << endl;
    cout << "       FINAL ORDER SUMMARY      " << endl;
    cout << "===============================" << endl;

    for (int i = 0; i < count; i++) {
        orders[i].displayOrder(i + 1);
    }

    double totalPrice = count * CoffeeOrder::getPrice();

    cout << "-------------------------------" << endl;
    cout << "Total Coffees: " << count << endl;
    cout << fixed << setprecision(2);
    cout << "Total Price:   $" << totalPrice << endl;
    cout << "===============================" << endl;

    return 0;
}