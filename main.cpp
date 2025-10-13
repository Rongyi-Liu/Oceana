#include <iostream>
#include "BattleGame.h"
#include "GameInterface.h"

int main() {
    GameInterface::displayWelcome();

    // (Optional demo) Observe static before any game:
    // std::cout << "Games played so far: " << BattleGame::getTotalGamesPlayed() << "\n\n";

    while (true) {
        // Names could be prompted; fixed here to keep workshop focused
        BattleGame game("Player 1", "Player 2");

        // Run one full game
        while (game.getGameState() == GameState::PLAYING) {
            ActionType p1 = GameInterface::getPlayerAction("Player 1");
            ActionType p2 = GameInterface::getPlayerAction("Player 2");

            game.executeTurn(p1, p2);
            GameInterface::displayTurnResult(p1, p2);
            game.displayStatus();
        }

        // Game ended
        GameInterface::displayWinner(game.getGameState());
        BattleGame::displayStatistics();

        if (!GameInterface::promptPlayAgain()) break;
        std::cout << "\n";
    }

    GameInterface::displayGoodbye();
    return 0;
}
