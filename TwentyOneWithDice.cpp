#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Die {
private:
    int value;

public:
    // Static constant field for the maximum die value
    static const int MAX_VALUE = 6;

    // Function to "roll" the die (sets the value to a random number 1-6)
    void roll() {
        value = (rand() % MAX_VALUE) + 1;
    }

    // Setter for the value (if manual setting is needed)
    void setValue(int val) {
        if (val >= 1 && val <= MAX_VALUE) {
            value = val;
        }
    }

    // Getter to retrieve the current value
    int getValue() const {
        return value;
    }
};

int main() {
    // Seed the random number generator using the current time
    srand(static_cast<unsigned int>(time(0)));

    Die gameDie;
    int playerTotal = 0;
    int computerTotal = 0;
    char choice;

    cout << "     welcome to the game of 21 (dice edition) ---" << endl;

    // Player's Turn
    bool playerDone = false;
    while (!playerDone && playerTotal <= 21) {
        cout << "\nyour current total: " << playerTotal << endl;
        cout << "would you like to roll? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            gameDie.roll();
            int rollValue = gameDie.getValue();
            playerTotal += rollValue;
            cout << "you rolled a " << rollValue << ". new total: " << playerTotal << endl;

            if (playerTotal > 21) {
                cout << "bust! You went over 21." << endl;
                playerDone = true;
            }
        } else {
            playerDone = true;
        }
    }

    // Computer's Turn (only rolls if the player hasn't busted yet)
    if (playerTotal <= 21) {
        cout << "\ncomputer's turn..." << endl;
        while (computerTotal < 19) {
            gameDie.roll();
            computerTotal += gameDie.getValue();
            cout << "computer rolls... total is now " << computerTotal << endl;
        }
    }

    // Determine the winner
    cout << "\n     final results     " << endl;
    cout << "player total:   " << playerTotal << endl;
    cout << "computer total: " << computerTotal << endl;

    if (playerTotal > 21) {
        cout << "computer wins! (PLAYER BUSTED)" << endl;
    } else if (computerTotal > 21) {
        cout << "player wins! (COMPUTER BUSTED)" << endl;
    } else if (playerTotal >= computerTotal) {
        // Includes the rule: If both stop with same total (19, 20, or 21), player wins.
        cout << "player wins!" << endl;
    } else {
        cout << "computer wins!" << endl;
    }

    return 0;
}
