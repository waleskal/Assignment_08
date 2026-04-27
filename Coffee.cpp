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
    
    void setOrder() {
        cout << "enter 1 for Yes, 0 for No for the following options:" << endl;
        
        cout << "add cream? ";
        cin >> cream;
        cout << "add milk? ";
        cin >> milk;
        cout << "add sugar? ";
        cin >> sugar;
        cout << "add artificial sweetener? ";
        cin >> sweetener;

        
        if (milk == 1 && cream == 1) {
            milk = 0;
            cout << "\n* note: both milk and cream selected. defaulting to cream only." << endl;
        }

       
        if (sugar == 1 && sweetener == 1) {
            sweetener = 0;
            cout << "* note: both sugar and sweetener selected. defaulting to sugar only." << endl;
        }
    }

    
    void displayOrder() {
        cout << "\n    your coffee order     " << endl;
        cout << "base price: $" << fixed << setprecision(2) << COFFEE_PRICE << endl;
        cout << "ingredients: " << endl;
        
        cout << " - cream:     " << (cream ? "Yes" : "No") << endl;
        cout << " - milk:      " << (milk ? "Yes" : "No") << endl;
        cout << " - sugar:     " << (sugar ? "Yes" : "No") << endl;
        cout << " - sweetener: " << (sweetener ? "Yes" : "No") << endl;
        cout << "-------------------------" << endl;
    }
};

const double CoffeeOrder::COFFEE_PRICE = 1.25;

int main() {
    CoffeeOrder myOrder;

    
    myOrder.setOrder();
    myOrder.displayOrder();

    return 0;
}
