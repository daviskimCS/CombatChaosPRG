#include "../header/enemy.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(string nameIn, int typeIn, string dialogueIn) {
    this->setName(nameIn);
    this->setType(typeIn);
    this->setDialogue(dialogueIn);
}

void Enemy::setDialogue(string dialogue) {
    this->dialogue = dialogue;
}

string Enemy::getDialogue() {
    return this->dialogue;
}

void Enemy::playDialogue() {
    cout << this->getDialogue() << endl;
}