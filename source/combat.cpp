#include "../header/combat.h"
#include "../header/character.h"
#include "../header/player.h"
#include "../header/enemy.h"

#include <iostream>

using namespace std;

//compares both character's speeds to determine who attacks first
bool Combat::compareSpeed() {
    if (player->getSpeed() > enemy->getSpeed()) {
        return true;
    }
    else {
        return false;
    }
}

//calculates damage from character's strength stat
int Combat::calculateDmg(Character* c) {
    return c->getStrength() / 2;
}

// Public member functions
//constructor
Combat::Combat(Character* p, Character* e){
    this->player = p;
    this->enemy = e;
}

void Combat::dmgDealt(int playerDmg, int enemyDmg) {
    cout << "    Player dealt " << playerDmg << " damage." << endl;
    //subtracts dmg dealt from current health and sets it as current
    enemy->setHealth(enemy->getHealth() - playerDmg); 
    cout << "    Enemy health remaining: " << enemy->getHealth() << endl;

    if (!(enemy->isAlive())) {
        cout << "    Enemy defeated!" << endl;
        return;
    }

    cout << "    Enemy dealt " << enemyDmg << " damage." << endl;
    //subtracts dmg dealt from current health and sets it as current
    player->setHealth(player->getHealth() - enemyDmg);
    cout << "    Player health remaining: " << player->getHealth() << endl;

    if (!(player->isAlive())) {
        cout << "    Player defeated!" << endl;
        return;
    }
}

//if enemy is faster
void Combat::dmgDealt2(int playerDmg, int enemyDmg) {
    cout << "    Enemy dealt " << enemyDmg << " damage." << endl;
    //subtracts dmg dealt from current health and sets it as current
    player->setHealth(player->getHealth() - enemyDmg);
    cout << "    Player health remaining: " << player->getHealth() << endl;

    if (!(player->isAlive())) {
        cout << endl << "    Player defeated!" << endl;
        return;
    }

    cout << "    Player dealt " << playerDmg << " damage." << endl;
    //subtracts dmg dealt from current health and sets it as current
    enemy->setHealth(enemy->getHealth() - playerDmg); 
    cout << "    Enemy health remaining: " << enemy->getHealth() << endl;

    if (!(enemy->isAlive())) {
        cout << "    Enemy defeated!" << endl;
        return;
    }
}

void Combat::Outcome() {
    if (!(player->isAlive())) {
        cout << "Enemy wins!" << endl;
    }
    else {
        cout << "Player wins!" << endl;
    }
}

// Getter function for player character
Character* Combat::getPlayer() const {
    return player;
}

// Getter function for enemy character
Character* Combat::getEnemy() const {
    return enemy;
}