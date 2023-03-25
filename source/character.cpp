#include "../header/character.h"
#include <iostream>
#include <string>

Character::Character() {
    name = "";
    type = 0;
    hp = 25;
    strength = 5;
    speed = 5;
}

//sets character's name
void Character::setName(std::string nameIn) {
    this->name = nameIn;
}

//returns character's name
string Character::getName() {
    return this->name;
}

//sets character's health
void Character::setHealth(int hp) {
    this->hp = hp;
}

//returns character's health
int Character::getHealth() {
    return this->hp;
}

//sets character's strength
void Character::setStrength(int strength) {
    this->strength = strength;
}

//returns character's strength
int Character::getStrength() {
    return this->strength;
}

//sets character's speed
void Character::setSpeed(int speed) {
    this->speed = speed;
}

//returns character's speed
int Character::getSpeed() {
    return this->speed;
}

//sets character's type
void Character::setType(int typeIn) {
    switch (typeIn) 
    {
        //Rogue type: high speed, low strength
        case 1: {
            string name = this->getName().append(" - Rogue");
            this->setName(name);

            int speed = this->getSpeed() + 5;
            this->setSpeed(speed);

            int strength = this->getStrength() - 2;
            this->setStrength(strength);
            break;
        }
        //Tank type: high health, low speed
        case 2: {
            string name = this->getName() + " - Tank";
            this->setName(name);

            int hp = this->getHealth() + 10;
            this->setHealth(hp);

            int speed = this->getSpeed() - 2;
            this->setSpeed(speed);

            break;
        }
        //Fighter type: high strength, low health
        case 3: {
            string name = this->getName() + " - Fighter";
            this->setName(name);

            int strength = this->getStrength() + 5;
            this->setStrength(strength);

            int hp = this->getHealth() - 5;
            this->setHealth(hp);

            break;
        }
    }
    return;
}

//returns true if character's health is greater than 0
bool Character::isAlive() {
    if (this->getHealth() > 0) {
        return true;
    } else {
        return false;
    }
}

//modifies character's health
void Character::takeDamage(int damage) {
    int projectedHp = this->getHealth() - damage;
    this->setHealth(projectedHp);
}