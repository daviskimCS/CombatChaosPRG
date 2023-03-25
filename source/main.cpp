#include "../header/character.h"
#include "../header/combat.h"
#include "../header/enemy.h"
#include "../header/game.h"
#include "../header/inventory.h"
#include "../header/player.h"
#include "../header/stage.h"
#include <string>

using namespace std;

int main() {
    Game testGame;
    testGame.startGame();
    testGame.mainPhase();
    testGame.gameOver();
    return 0;
}