#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using std::string;

class Character {
    private:
        string name = "";
        int hp = 0;
        int type = 0;
        int strength = 0;
        int speed = 0;

    public:
        Character();
        void setName(string);
        string getName();
        void setHealth(int);
        int getHealth();
        void setStrength(int);
        int getStrength();
        void setSpeed(int);
        int getSpeed();
        void setType(int);
        bool isAlive();
        void takeDamage(int);
};

#endif