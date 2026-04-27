#include <iostream>
#include <string>

using namespace std;

class Order {
private:
    
    int tableNumber;
    string serverName;
    int numberOfPatrons;

    
    static double minTableCharge;

public:
    
    static void displayMinimumCharge() {
        cout << "the minimum charge per table is: $" << minTableCharge << endl;
    }
};


double Order::minTableCharge = 4.75;

int main() {
    
    Order::displayMinimumCharge();

    return 0;
}