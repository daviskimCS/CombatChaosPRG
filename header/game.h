#include "../header/stage.h"
#include "../header/player.h"

class Game {
    private:
        vector<Stage> board;
        Player* user;
        Stage playerPosition;
        
    public:
        Game();
        ~Game();
        void startGame();
        void gameOver();
        void playerPositionDesc();
        void presentItems();
        void combatPhase();
        void idlePhase();
        void mainPhase();
};