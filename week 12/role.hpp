#ifndef __ROLE_H__
#define __ROLE_H__
#include "string.hpp"

enum Status {ALIVE, HURT, DEAD}; // bool isAlive + bool isHurt
enum Team {GOOD, BAD, NONE}; // bool isAlive + bool isHurt


class Role {
    Status status;
    String username;
    Team isBad;

public:
    Role(const String& name, const Team& isBad): username(name), isBad(isBad), status(ALIVE) {}


    public:
    const String& getUsername() const {
        return username;
    }

    bool getIsBad() const {
        return isBad;
    }

    bool isAlive() const {
        return status == ALIVE;
    }

    void setHurt() {
        if (status == ALIVE) {
            status = HURT;
        }
    }

    void setAlive() {
        if (status == HURT) {
            status = ALIVE;
        }
    }

    virtual void attack(Role* other) const = 0;
};

class Werewolf: public virtual Role {
    public:
    Werewolf(const String& name): Role(name, BAD) {}

    void attack(Role* other) const {
        if (this->isAlive() && (Role*)this != other) {
            other->setHurt();
        }
    }
};

class Villager: public virtual Role {
    public:
    Villager(const String& name): Role(name, GOOD) {}

    void attack(Role* other) const {}
};

class Healer: public Role {
    public:
    Healer(const String& name): Role(name, GOOD) {}

    void attack(Role* other) const {
        if (this->isAlive() && (Role*)this != other) {
            other->setAlive();
        }
    }
};

class Shapeshifter: public Werewolf, public Villager {
    bool canAttack;

    public:
    Shapehifter(const String& username): Werewolf(username), Villager(username), Role(username, NONE) {
        canAttack = false;
    }

    void attack(Role* other) const {
        if (canAttack) {
            Werewolf::attack(other);
        } else {
            Villager::attack(other);
        }

        canAttack = !canAttack;
    }
}

#endif // __ROLE_H__