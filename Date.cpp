#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

    static char slash;


    void setMonth(int m) {
        if (m > 12) month = 12;
        else if (m < 1) month = 1; 
        else month = m;
    }

    void setDay(int d) {
        if (d > 31) day = 31;
        else if (d < 1) day = 1;
        else day = d;
    }

    void setYear(int y) {
        year = y;
    }

public:
    
    void setDate(int m, int d, int y) {
        setMonth(m);
        setDay(d);
        setYear(y);
    }

    void showDate() {
        cout << month << slash << day << slash << year << endl;
    }
};


char Date::slash = '/';

int main() {
    Date d1, d2, d3;

    
    d1.setDate(10, 15, 2024);
    cout << "Date 1: ";
    d1.showDate();

    
    d2.setDate(15, 20, 2025);
    cout << "Date 2 (Month 15): ";
    d2.showDate();

    
    d3.setDate(5, 45, 2026);
    cout << "Date 3 (Day 45): ";
    d3.showDate();

    return 0;
}