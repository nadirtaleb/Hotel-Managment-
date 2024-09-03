#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int month;
    int day;
    int year;
public:
    Date();
    Date(int m, int d, int y);

    int getMonth() const;
    int getDay() const;
    int getYear() const;
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    bool operator>(const Date& other) const;
};

#endif
