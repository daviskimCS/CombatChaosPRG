#include "../header/inventory.h"
#include "../header/player.h"
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

Inventory::Inventory() {
    //Initializing player inventory with all items with amount 0
    Item str1("damageBoost", "damage", "increases attack stat by 5 points for the duration of the battle", 0, 5);
    Item spe1("speedBoost", "speed", "increases speed stat by 5 points for the duration of the battle", 0, 5);
    Item hp1("healthBoost", "health", "increases health stat by 10 points", 0, 10);

    //including items that last for partial duration of match (ex: 5+ of damage for 5 turns)
    Item str2("damageIncrease", "damage", "increases attack stat permanently by 5 points", 0, 5);
    Item spe2("speedIncrease", "speed", "increases speed stat permanently by 5 points", 0, 5);
    Item hp2("healthIncrease", "health", "increases health stat by 20 points", 0, 30);

    //item to show if empty or item not found
    Item nullItem;

    container.push_back(nullItem);
    container.push_back(str1);
    container.push_back(spe1);
    container.push_back(hp1);
    container.push_back(str2);
    container.push_back(spe2);
    container.push_back(hp2);
}

void Inventory::addItemI(std::string itemIn) {
    for(int i = 1; i < this->container.size() - 1; ++i) {
        if(this->container[i].getName() == itemIn) {
            this->container[i].changeAmount(1);
            cout << itemIn << " added to players inventory!" << endl << endl;
            return;
        }
    }
    cout << "Item requested to being added to player inventory was not found." << endl;
    cout << "Please try again. Item names are case sensitive." << endl << endl;
    return;
}

Item Inventory::useItemI(std::string itemIn) {
    if(this->isEmpty()) {
        cout << "      No items can be used since your inventory is empty." << endl;
    }
    else {
        for(int i = 1; i < this->container.size(); ++i) {
            if(this->container[i].getName() == itemIn) {
                if(this->container[i].getAmount() > 0) {
                    this->container[i].changeAmount(-1);
                    return this->container[i];
                }
                else {
                    cout << "Item cannot be used since there is none in your inventory." << endl;
                    return this->container[0];
                }
            }
        }
        cout << "Item specified is not found in inventory." << endl;
        cout << "Please try again. Selection is case-sensitive." << endl;
    }
    return this->container[0];
}

void Inventory::displayItems() {
    if(this->isEmpty()) {
        cout << "      No items to be displayed since your inventory is empty." << endl;
    }
    else {
        int numberItem = 1;
        for(int i = 1; i < this->container.size(); ++i) {
            if(this->container[i].getAmount() != 0) {
                cout << "    " << numberItem << ". ";
                this->container[i].displayInfo();
                ++numberItem;
            }
        }
    }
}

bool Inventory::isEmpty() {
    for(unsigned int i = 1; i < this->container.size(); ++i) {
        if(this->container[i].getAmount() > 0) {
            return false;
        }
    }
    return true;
}

Item::Item() {
    name = "null";
    itemType = "";
    description = "";
    amount = 0;
    magnitude = 0;
}

Item::Item(std::string nameIn, std::string typeIn, std::string descriptionIn, int amountIn, int magnitudeIn) {
    this->name = nameIn;
    this->itemType = typeIn;
    this->description = descriptionIn;
    this->amount = amountIn;
    this->magnitude = magnitudeIn;
}

void Item::displayInfo() {
    cout << "Name: " << this->name << endl;
    cout << "      Description: " << this->description << endl;
    cout << "      Amount: " << this->amount << endl;
    cout << "      Magnitude: " << this->magnitude << endl;
}

int Item::getAmount() {
    return amount;
}

void Item::changeAmount(int changeInt) {
    this->amount += changeInt;
}

string Item::getName() {
    return name;
}

string Item::getItemType() {
    return itemType;
}

int Item::getMagnitude() {
    return magnitude;
}