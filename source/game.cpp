#include "../header/game.h"
#include "../header/combat.h"
#include "../header/stage.h"
#include "../header/player.h"
#include "../header/enemy.h"
#include "../header/inventory.h"
#include <string.h>
#include <iostream>
#include <limits>

using namespace std;

Game::Game() {
    user = new Player();

    string stage1name = "The Beginner's Grove";
    string stage1desc = "Welcome to The Beginner's Grove! This is where your journey begins in a peaceful and secluded area nestled"
    " within a dense forest. Explore the grove to discover wonders and resources, but be wary of dangers like hostile creatures and"
    " hidden traps. Gain experience and learn game mechanics to prepare for greater adventures that await you beyond the grove.";
    Stage stage1(stage1name,stage1desc);
    stage1.add_item("damageBoost");
    stage1.add_item("speedBoost");
    stage1.add_item("healthBoost");

    string stage2name = "The Path of Trials";
    string stage2desc = "Welcome to The Path of Trials! After exploring the peaceful grove, you must now face greater challenges"
    " on your journey. The path ahead is filled with puzzles, combat, and other trials that you must overcome to progress."
    " You'll need to use all your skills and wits to survive and succeed. Can you prove yourself worthy and continue on your journey?";
    Stage stage2(stage2name, stage2desc);
    stage2.add_item("damageIncrease");
    stage2.add_item("speedIncrease");
    stage2.add_item("healthIncrease");

    string stage3name = "The Caverns of Mystery";
    string stage3desc = "Welcome to The Caverns of Mystery! After braving the trials on the path, you must now delve deep into"
    " underground caverns to continue your journey. The caverns are filled with secrets, hidden treasures, and unknown dangers"
    " that you must navigate to progress. Can you uncover the mysteries hidden within the depths of the caverns? Beware, for the"
    " shadows hold many secrets and dangers. Will you emerge triumphant, or will you succumb to the mysteries that await you?";
    Stage stage3(stage3name, stage3desc);
    stage3.add_item("damageIncrease");
    stage3.add_item("speedIncrease");
    stage3.add_item("healthIncrease");

    board.push_back(stage1);
    board[0].badGuy = new Enemy("Trialmaster Grom", 3, "\"You there, challenger,\" booms a deep, rumbling voice"
    " as you step into the arena. \"I am Grom, the Trialmaster, and you have entered"
    " my domain. Do you seek to prove your worth? Or are you merely another fool who"
    " will fall to my blade? We shall see.\"");

    board.push_back(stage2);
    board[1].badGuy = new Enemy("Earth Titan", 2, "The ground shakes beneath your feet as a massive creature bursts forth from the earth, towering over"
    " you like a mountain. \"You dare to trespass in my domain?\" it bellows, its voice like the rumble of distant thunder."
    " \"I am the Earth Titan, and you shall not leave this place alive!\"");

    board.push_back(stage3);
    board[2].badGuy = new Enemy("Boss Baby", 1, "Boss Baby is a formidable opponent. He stands tall and proud, with a smug expression"
    " on his face that suggests he knows he's about to win. His tiny hands are clenched tightly into fists, and his chubby cheeks are"
    " puffed out with determination. \n \"So, you think you can take me on?\" he says, his voice dripping with condescension."
    "\"Ha! You don't stand a chance against my superior intellect and business acumen.\" \n He throws his suitcase to the side, and"
    " raises his rattle, ready.");

    playerPosition = board[0];
}

void Game::startGame() {
    cout << "Welcome to Combat Chaos! In this game, you will choose a character and battle against enemies, picking up different items along the way." << endl;
    cout << "To begin, please enter your name: " << endl;

    string playerName;
    cin >> playerName;
    this->user->setName(playerName);
    cout << endl << "Hello, " << user->getName() << "!" << endl;

    this->playerPositionDesc();

    cout << endl;
    cout << "In this game you can choose between 3 classes: " << endl;
    cout << "      Rogue   (1) is a low strength, but high speed class." << endl;
    cout << "      Tank    (2) is a low speed, but high health class." << endl;
    cout << "      Fighter (3) is a low health, but high strength class." << endl;

    int classNo = 0;

    cout << "Please enter in the number of the class that you want to play as!" << endl;

    while((!(cin >> classNo)) || classNo < 1 || classNo > 3) {
        cout << "Number input was invalid. Please input the value followed by the class name." << endl;
        cout << "Input 1 for Rogue Example: Rogue (1)" << endl;
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    this->user->setType(classNo);
    cout << endl;
    cout << "You will now be referred to as " << user->getName() << endl;

    return;
}  

void Game::idlePhase() {
    if(this->user->isAlive()) {
        this->user->showInfo();
        cout << endl << "Here are the items you have that you can use!" << endl;
        this->user->showInventory();

        cout << endl;

        this->presentItems();
        string strPlayerPos = this->playerPosition.get_description();

        string strBoardPos0 = this->board[0].get_description();
        string strBoardPos1 = this->board[1].get_description();
        string strBoardPos2 = this->board[2].get_description();

        if(strcmp(strPlayerPos.c_str(), strBoardPos2.c_str()) == 0) {
            if(strcmp(strPlayerPos.c_str(), strBoardPos1.c_str()) == 0) {
                playerPosition = this->board[1];
                this->playerPositionDesc();
            }
            else {
                playerPosition = this->board[2];
                this->playerPositionDesc();
            }
            return;
        }
        else {
            return;
        }
    }
    else {
        return;
    }
}

void Game::mainPhase() {
    //number of stages
    int noStages = 0;
    while(user->isAlive() && noStages < 3) {
        this->idlePhase();
        this->combatPhase();
        if(noStages < 2) {
            playerPosition = board[noStages + 1];
            this->playerPositionDesc();
            cout << endl;
        }
        ++noStages;
    }
}

void Game::combatPhase() {
    Combat phase(user, playerPosition.getEnemy());
    cout << endl << playerPosition.getEnemy()->getName() << " appeared and is starting to fight you!" << endl;
    playerPosition.getEnemy()->getDialogue();
    cout << endl;

    int decision = 0;
    int playerDamage = 0;
    int enemyDamage = 0;
    while((playerPosition.getEnemy())->isAlive() && this->user->isAlive()) {
        cout << endl;
        cout << "Choose option: (1) attack, (2) dodge, or (3) defend." << endl;

        while((!(cin >> decision)) || decision < 1 || decision > 3) {
            cout << "Number input was invalid. Please input the value before by the option name." << endl;
            cout << "Input 1 for attack Example: (1) attack" << endl;
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(phase.compareSpeed()) {
            cout << "You moved first!" << endl;
            if(decision == 1) {
                playerDamage = phase.calculateDmg(this->user);
                enemyDamage = phase.calculateDmg(playerPosition.getEnemy()) / 2;
                phase.dmgDealt(playerDamage, enemyDamage);
            }
            else if(decision == 2) {
                cout << "You successfully dodged their attack!" << endl;
            }
            else {
                cout << "You successfully defended their attack!" << endl;
                playerDamage = 0;
                enemyDamage = phase.calculateDmg(playerPosition.getEnemy()) / 4;
                phase.dmgDealt2(playerDamage, enemyDamage);
            }
        }
        else {
            cout << playerPosition.getEnemy()->getName() << " moved first!" << endl;
            if(decision == 1) {
                playerDamage = phase.calculateDmg(this->user);
                enemyDamage = phase.calculateDmg(playerPosition.getEnemy()) / 2;
                phase.dmgDealt2(playerDamage, enemyDamage);
            }
            else if(decision == 2) {
                cout << "You were too slow to dodge their attack!" << endl;
                playerDamage = 0;
                enemyDamage = phase.calculateDmg(playerPosition.getEnemy()) / 2;
                phase.dmgDealt2(playerDamage, enemyDamage);
            }
            else {
                cout << "You were too slow to completely defend their attack!" << endl;
                playerDamage = 0;
                enemyDamage = phase.calculateDmg(playerPosition.getEnemy()) * 0.4;
                phase.dmgDealt2(playerDamage, enemyDamage);
            }
        }
        decision = 0;
        playerDamage = 0;
        enemyDamage = 0;
    }
    phase.Outcome();
}

void Game::playerPositionDesc() {
    cout << "Currently you are at " << playerPosition.get_name() << ". " << endl << endl;
    cout << playerPosition.get_description() << endl;
}

void Game::presentItems() {
    cout << "Here are the free items available for you to choose from: " << endl;
    for(unsigned int i = 0; i < this->playerPosition.showItems().size(); ++i) {
        cout << "   " << i + 1 << ". " << this->playerPosition.showItems().at(i) << endl;
    }
    
    string itemName = "";
    cout << "Please enter the name of the item that you want!" << endl;
    cin >> itemName;

    while(!this->playerPosition.has_item(itemName)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> itemName;
    }
    user->addItem(itemName);
    cout << "      Using " << itemName <<  "!" << endl;
    user->useItem(itemName);
    this->user->showInfo();
    return;
}

void Game::gameOver() {
    if (user->isAlive() == false) {
        cout << "You died. Goodbye, " << this->user->getName() << "." << endl;
        return;
    }
    else if (user->isAlive() == true) {
        cout << "You survived! Congrats, " << this->user->getName() << ". You win the game!" << endl;
        return;
    }
    cout << "gameOver() returned false incorrectly." << endl;
    return;
}

Game::~Game() {
    delete this->user;
    delete board[2].getEnemy();
    delete board[1].getEnemy();
    delete board[0].getEnemy();
}