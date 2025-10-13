#pragma once
#include <string>
#include "Player.h"

// === Enums ===
// Use scoped enums for type-safety
enum class ActionType { LIGHTATTACK = 1, HEAVYATTACK = 2, BLOCK = 3 };
enum class GameState { PLAYING, PLAYER1_WON, PLAYER2_WON, DRAW };

class BattleGame {
private:
    Player player1;
    Player player2;
    GameState currentState;

    // Static, shared across all BattleGame instances
    static int totalGamesPlayed;
    static int totalDamageDealt;
    static int player1Wins;
    static int player2Wins;

    // Helpers
    int calculateDamage(ActionType action) const;
    void resolveAttacks(ActionType p1Move, ActionType p2Move);
    void updateGameState();

public:
    BattleGame(const std::string& p1Name, const std::string& p2Name);

    // Per-game operations
    void executeTurn(ActionType p1Move, ActionType p2Move);
    void displayStatus() const;
    GameState getGameState() const { return currentState; }

    // Global statistics
    static void displayStatistics();
    static int getTotalGamesPlayed() { return totalGamesPlayed; }

    // Expose players' names (optional convenience)
    const Player& getPlayer1() const { return player1; }
    const Player& getPlayer2() const { return player2; }
};
