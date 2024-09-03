#include "Date.h"

Date::Date() : month(1), day(1), year(2024) {}
Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }
void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}

bool Date::operator>(const Date& other) const {
    if (year > other.year) return true;
    if (year == other.year && month > other.month) return true;
    if (year == other.year && month == other.month && day > other.day) return true;
    return false;
}
