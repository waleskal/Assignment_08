#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Order {
private:
    
    int tableNumber;
    string serverName;
    int numberOfPatrons;

    
    static double minTableCharge;

public:
    
    void setTableNumber(int tn) { tableNumber = tn; }
    void setServerName(string sn) { serverName = sn; }
    void setNumberOfPatrons(int np) { numberOfPatrons = np; }

    
    void displayOrderInfo() {
        double totalMinCharge = minTableCharge * numberOfPatrons;

        cout << fixed << setprecision(2);
        cout << "\n    order details     " << endl;
        cout << "table number:    " << tableNumber << endl;
        cout << "server:          " << serverName << endl;
        cout << "patrons:         " << numberOfPatrons << endl;
        cout << "minimum table fee:   $" << minTableCharge << " per person" << endl;
        cout << "total minimum due:   $" << totalMinCharge << endl;
        cout << "----------------------" << endl;
    }
};


double Order::minTableCharge = 4.75;

int main() {
    
    Order myOrder;

    
    myOrder.setTableNumber(12);
    myOrder.setServerName("chris");
    myOrder.setNumberOfPatrons(4);

    myOrder.displayOrderInfo();

    return 0;
}

