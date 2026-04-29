#ifndef __USER_H__
#define __USER_H__
#include <iostream>
#include "string.hpp"

class User {
    String username;
    String password;
    String name;

protected: 
    User(const String& username, const String& password, const String& name) {
        this->username = username;
        this->password = password;
        this->name = name;
    }

// public:
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.username << ": " << user.name;

    return os;
}

#endif // __USER_H__