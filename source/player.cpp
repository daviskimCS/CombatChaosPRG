#include "../header/inventory.h"
#include "../header/character.h"
#include "../header/player.h"
#include <vector>
#include <iostream>

using namespace std;

Player::Player() {
    this->playerInventory = Inventory();
}

void Player::useItem(string itemIn) {
    Item usedItem = playerInventory.useItemI(itemIn);
    string usedItemType = usedItem.getItemType();
    if (usedItemType.compare("damage") == 0) {
        int changedStrength = this->getStrength() + usedItem.getMagnitude();
        this->setStrength(changedStrength);
    }
    else if (usedItemType.compare("speed") == 0) {
        int changedSpeed = this->getSpeed() + usedItem.getMagnitude();
        this->setSpeed(changedSpeed);
    }
    else if (usedItemType.compare("health") == 0) {
        int changedHealth = this->getHealth() + usedItem.getMagnitude();
        this->setHealth(changedHealth);
    } else {
        cout << "Nice try, bud. You're done." << endl;
    }
    // this->playerInventory.useItemI(itemIn);
}

void Player::addItem(string itemIn) {
    this->playerInventory.addItemI(itemIn);
    return;
}

void Player::showInventory() {
    if(playerInventory.isEmpty()) {
        cout << "No items in inventory to display." << endl;
    }
    else { 
        playerInventory.displayItems();
    }
}

void Player::showInfo() {
    cout << "Your current stats:" << endl;
    cout << "   Health: " << this->getHealth() << endl;
    cout << "   Speed: " << this->getSpeed() << endl;
    cout << "   Strength: " << this->getStrength() << endl;
}