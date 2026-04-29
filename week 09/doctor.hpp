#ifndef __DOCTOR_H__
#define __DOCTOR_H__
#include "user.hpp"
#include "pair.hpp"
#include "vector.hpp"
#include "time.hpp"

class Doctor: User {
    Vector<Pair<Time, bool>> schedule;

    public:
    Doctor(const String& username, const String& password, 
        const String& name): 
        User(username, password, name) {}

    void addTimeslot(const Time& timeslot) {
        // true - free, false - busy
        Pair<Time, bool> p(timeslot, true);
        schedule.append(p);
    }

    friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor);
};

std::ostream& operator<<(std::ostream& os, const Doctor& doctor) {
    os << (User)doctor;

    return os;
}

class Surgeon: public Doctor {
    public:
    Surgeon(const String& username, const String& password, 
        const String& name): 
        Doctor(username, password, name) {}
}

class Dentist: public Doctor {
    public:
    Dentist(const String& username, const String& password, 
        const String& name): 
        Doctor(username, password, name) {}
}


#endif // __DOCTOR_H__