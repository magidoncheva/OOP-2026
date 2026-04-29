#ifndef __TIME_H__
#define __TIME_H__
#include <iostream>

class Time {
    unsigned hours, minutes;

    public:
    Time(const unsigned& hours = 0, const unsigned& minutes = 0): 
        hours(hours), minutes(minutes){}

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.hours << ":" << time.minutes;

    return os;
}

#endif // __TIME_H__