#pragma once
#include <string>
#include "BattleGame.h"

// Utility class: all methods are static
class GameInterface {
public:
    static void displayWelcome();
    static void displayGoodbye();
    static ActionType getPlayerAction(const std::string& who);
    static void displayTurnResult(ActionType p1, ActionType p2);
    static void displayWinner(GameState state);
    static bool promptPlayAgain();
};
