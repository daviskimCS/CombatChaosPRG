#ifndef COMBAT_H
#define COMBAT_H

#include "character.h"

class Combat {
    private:
        Character* player;
        Character* enemy;

    public:
        bool compareSpeed();
        int calculateDmg(Character*);
        Combat(Character*, Character*);
        void dmgDealt(int, int);
        void dmgDealt2(int, int);
        void Outcome();
        Character* getPlayer() const;
        Character* getEnemy() const;
        ~Combat() {};
};

#endif