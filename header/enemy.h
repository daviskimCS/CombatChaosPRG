#ifndef ENEMY_H
#define ENEMY_H

#include "../header/character.h"
#include <string>

class Enemy : public Character {
    private:
        string dialogue = "";

    public:
        Enemy();
        ~Enemy() {};
        Enemy(string, int, string);
        void setDialogue(string);
        string getDialogue();
        void playDialogue();
};

#endif