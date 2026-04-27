#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    static char slash;

    
    int getMaxDays() {
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } 
        else if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
                return 29;
            return 28;
        } 
        return 31;
    }

    void setMonth(int m) {
        if (m > 12) month = 12;
        else if (m < 1) month = 1;
        else month = m;
    }

    void setDay(int d) {
        int max = getMaxDays();
        if (d > max) day = max;
        else if (d < 1) day = 1;
        else day = d;
    }

    void setYear(int y) { year = y; }

public:
    void setDate(int m, int d, int y) {
        setMonth(m);
        setYear(y); 
        setDay(d);
    }


    void increaseDay() {
        day++;
        if (day > getMaxDays()) {
            day = 1;
            month++;
            
            
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void showDate() {
        cout << month << slash << day << slash << year << endl;
    }
};

char Date::slash = '/';

int main() {
    
    Date d1, d2, d3;

    d1.setDate(2, 26, 2024);  
    d2.setDate(4, 28, 2025);  
    d3.setDate(12, 29, 2025); 

    Date dates[] = {d1, d2, d3};
    string labels[] = {"Leap Year Test", "30-Day Month Test", "Year End Test"};

    for (int i = 0; i < 3; i++) {
        cout << "--- " << labels[i] << " ---" << endl;
        cout << "Starting: ";
        dates[i].showDate();

        
        for (int j = 1; j <= 5; j++) {
            dates[i].increaseDay();
            
            cout << "Day " << j << " increase: ";
            dates[i].showDate();
        }
        cout << endl;
    }

    return 0;
}