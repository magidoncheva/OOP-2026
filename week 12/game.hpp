#ifndef __GAME_H__
#define __GAME_H__
#include "role.hpp"
#include "vector.hpp"
#include <cstdlib>
#include <ctime>

class Game {
    Vector<Role*> roles;
    public:
    Game(const size_t& n) {
        std::srand(std::time({}));
        int good_roles = (n / 2) + 1;
        int bad_roles = n - good_roles;

        for (size_t i = 0; i < n; ++i) {
            String username;
            std::cin >> username;
            
            Role* player;
            bool roleAssign = false;

            do {
                int role = std::rand() % 3;
                // roleAssign = true;

                if (role == 0) {
                    if (bad_roles != 0) {
                        player = new Werewolf(username);
                        bad_roles --;
                        roleAssign = true;
                    }
                } else {
                    if (good_roles != 0) {
                        roleAssign = true;
                        good_roles --;

                        if (role == 1) {
                            player = new Villager(username);
                        } else {
                            player = new Healer(username);
                        }
                    } 
                }
            } while(!roleAssign);
            
            roles.append(player);
        }
    }

    void play() {
        bool gameOver = false;

        do {
            for (size_t i = 0; i < roles.lenght(); ++i) {
                String username;
                std::cin >> username;
                roles[i]->attack(username);
            }
        } while (!gameOver);
    }
}

#endif // __GAME_H__