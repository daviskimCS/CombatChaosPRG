#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Item {
    private:
        std::string name = "";
        std::string itemType = "";
        std::string description = "";
        int amount = 0;
        int magnitude = 0;
        
    public:
        Item();
        Item(std::string, std::string, std::string, int, int);
        void displayInfo();
        void changeAmount(int);
        int getAmount();
        string getName();
        string getItemType();
        int getMagnitude();
};

class Inventory {
    private:
        vector<Item> container;

    public:
        Inventory();
        void addItemI(std::string);
        Item useItemI(std::string);
        void displayItems();
        bool isEmpty();
};

#endif