#ifndef STAGE_H
#define STAGE_H

#include "./enemy.h"
#include <string>
#include <vector>

using namespace std;

class Stage {
    private:
        string name;
        string description;
        vector<string> items;

    public:
        Enemy* badGuy = NULL;
        Stage();
        ~Stage() {};
        Stage(string name, string description);
        void add_item(string item);
        void remove_item(string item);
        bool has_item(string item) const;
        string get_name() const;
        string get_description() const;
        vector<string> showItems() const {return items;};
        void setEnemy(Enemy* enemyIn) {this->badGuy = enemyIn;};
        Enemy* getEnemy() {return this->badGuy;};
};

#endif