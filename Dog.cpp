#include <iostream>
#include <string>
using namespace std;

class Dog {
private:
    string name;
    string breed;
    int age;
    static const double LICENSE_FEE;

public:
    void setData(string n, string b, int a) {
        name = n; breed = b; age = a;
    }
    void display() {
        cout << "dog: " << name << " | breed: " << breed 
             << " | age: " << age << " | license fee: $" << LICENSE_FEE << endl;
    }
};

// Initialize static member outside the class
const double Dog::LICENSE_FEE = 12.25;

int main() {
    Dog myDog;
    myDog.setData("rex", "german shepherd", 5);
    myDog.display();
    return 0;
}