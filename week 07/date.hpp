#ifndef __DATE_H__
#define __DATE_H__
#include <ctime>
#include <iostream>

class Date {
    unsigned year;
    unsigned month;
    unsigned day;

    public:
        Date();

        bool operator ==(const Date& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Date& obj); 
        friend std::istream& operator>>(std::istream& is, Date& obj); 
};

Date::Date() {
    time_t now = time(nullptr); 
    tm *ltm = localtime(&now);

    year = ltm->tm_year + 1900;
    month = ltm->tm_mon + 1;
    day = ltm->tm_mday;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

std::ostream& operator<<(std::ostream& os, const Date& obj) {
    os << obj.day << "." << obj.month << "." << obj.year;
    return os;
}
std::istream& operator>>(std::istream& is, Date& obj) {
    is >> obj.day >> obj.month >> obj.year;

    return is;
}

#endif // __DATE_H__