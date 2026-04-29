#ifndef __PATIENT_H__
#define __PATIENT_H__
#include "user.hpp"

class Patient: User {
    unsigned ucn;

public:
    Patient(const String& username, const String& password, 
        const String& name, const unsigned& ucn): 
        User(username, password, name) {
            this->ucn = ucn;
        }

    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
};

std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << (User)patient << " " << patient.ucn;

    return os;
}

#endif // __PACIENT_H__