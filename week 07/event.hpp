#ifndef __EVENT_H__
#define __EVENT_H__
#include "string.hpp"
#include "date.hpp"

class Event{
    String title, descr;
    Date date;

    public:
    friend std::ostream& operator<<(std::ostream& os, const Event& obj); 
    friend std::istream& operator>>(std::istream& is, Event& obj); 

};

std::ostream& operator<<(std::ostream& os, const Event& obj) {
    os << obj.date << ": " << obj.title << std::endl;
    os << "============================" << std::endl;
    os << obj.descr << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Event& obj) {
    is >> obj.date >> obj.title >> obj.descr;

    return is;
}

#endif // __EVENT_H__