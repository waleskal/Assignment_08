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

    void setYear(int y) { year = y; }

    void setDay(int d) {
        int max = getMaxDays();
        if (d > max) day = max;
        else if (d < 1) day = 1;
        else day = d;
    }

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
    
    Date myDate;
    myDate.setDate(12, 29, 2007);

    cout << "Starting Date: ";
    myDate.showDate();
    cout << "--------------------" << endl;

    
    for (int i = 1; i <= 400; i++) {
        myDate.increaseDay();
        
        
        cout << "Iteration " << i << ": ";
        myDate.showDate();
    }

    return 0;
}