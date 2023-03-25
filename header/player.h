#ifndef PLAYER_H
#define PLAYER_H

#include "../header/inventory.h"
#include "../header/character.h"
#include <vector>
#include <string>

class Player : public Character {
    private:
        Inventory playerInventory;
  
      public:
        Player();
        ~Player() {};
        void useItem(string);
        void addItem(string);
        void showInventory();
        void showInfo();
};

#endif