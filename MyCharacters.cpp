#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class GameCharacter {
private:
    string color;
    int numEyes;
    int numLegs;
    int numLives;
    int age;

public:
    void setColor(string c) { color = c; }
    void setEyes(int e) { numEyes = e; }
    void setLegs(int l) { numLegs = l; }
    void setAge(int a) { age = a; }
    void setLives(int lv) { numLives = lv; }

    string getColor() const { return color; }
    int getEyes() const { return numEyes; }
    int getLegs() const { return numLegs; }
    int getAge() const { return age; }
    int getLives() const { return numLives; }

};

void displayCharacterInfo(const GameCharacter& character) {
    cout << "    game character stats    " << endl;
    cout << "color:  " << character.getColor() << endl;
    cout << "age:    " << character.getAge() << endl;
    cout << "eyes:   " << character.getEyes() << endl;
    cout << "legs:   " << character.getLegs() << endl;
    cout << "lives:  " << character.getLives() << endl;
    cout << "----------------------------" << endl << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    
    GameCharacter c1, c2;

    c1.setColor("blue");
    c1.setLives(3);
    c1.setAge(rand() % 101);  
    c1.setEyes(rand() % 11);  
    c1.setLegs(rand() % 13);  

    c2.setColor("green");
    c2.setLives(5);
    c2.setAge(rand() % 101);
    c2.setEyes(rand() % 11);
    c2.setLegs(rand() % 13);

    
    displayCharacterInfo(c1);
    displayCharacterInfo(c2);

    return 0;
}