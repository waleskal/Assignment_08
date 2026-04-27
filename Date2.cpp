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

    void setYear(int y) {
        year = y;
    }

    void setDay(int d) {
        int maxDays;

        
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDays = 30;
        } 
        else if (month == 2) {
            
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                maxDays = 29;
            } else {
                maxDays = 28;
            }
        } 
        else {
            maxDays = 31;
        }

        
        if (d > maxDays) day = maxDays;
        else if (d < 1) day = 1;
        else day = d;
    }

public:
    void setDate(int m, int d, int y) {
        
        setMonth(m);
        setYear(y);
        setDay(d);
    }

    void showDate() {
        cout << month << slash << day << slash << year << endl;
    }
};

char Date::slash = '/';

int main() {
    Date d1, d2, d3, d4;

    d1.setDate(4, 31, 2024);
    cout << "April 31st (Expected 4/30): ";
    d1.showDate();


    d2.setDate(2, 29, 2024);
    cout << "Feb 29, 2024 (Leap):        ";
    d2.showDate();

    d3.setDate(2, 29, 2023);
    cout << "Feb 29, 2023 (Not Leap):    ";
    d3.showDate();


    d4.setDate(2, 30, 2000);
    cout << "Feb 30, 2000 (Expected 2/29): ";
    d4.showDate();

    return 0;
}