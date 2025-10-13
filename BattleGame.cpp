#include "BattleGame.h"
#include <iostream>

// === Static member definitions ===
int BattleGame::totalGamesPlayed = 0;
int BattleGame::totalDamageDealt = 0;
int BattleGame::player1Wins = 0;
int BattleGame::player2Wins = 0;

BattleGame::BattleGame(const std::string& p1Name, const std::string& p2Name)
    : player1(p1Name), player2(p2Name), currentState(GameState::PLAYING) {}

void BattleGame::executeTurn(ActionType p1Move, ActionType p2Move) {
    // Set blocking states
    player1.setBlocking(p1Move == ActionType::BLOCK);
    player2.setBlocking(p2Move == ActionType::BLOCK);

    // Resolve attacks and then check for end-of-game
    resolveAttacks(p1Move, p2Move);
    updateGameState();
}

int BattleGame::calculateDamage(ActionType action) const {
    switch (action) {
        case ActionType::LIGHTATTACK: return 15;
        case ActionType::HEAVYATTACK: return 30;
        case ActionType::BLOCK:       return 0;
        default:                      return 0;
    }
}

void BattleGame::resolveAttacks(ActionType p1Move, ActionType p2Move) {
    int p1Dmg = calculateDamage(p1Move);
    int p2Dmg = calculateDamage(p2Move);

    if (p1Dmg > 0) {
        player2.takeDamage(p1Dmg);
        totalDamageDealt += p1Dmg;
    }
    if (p2Dmg > 0) {
        player1.takeDamage(p2Dmg);
        totalDamageDealt += p2Dmg;
    }
}

void BattleGame::updateGameState() {
    bool p1Alive = player1.isAlive();
    bool p2Alive = player2.isAlive();

    if (p1Alive && p2Alive) {
        // Still playing
        return;
    }

    // Someone (or both) fell to 0 HP -> game over
    if (!p1Alive && !p2Alive) {
        currentState = GameState::DRAW;
    } else if (!p1Alive && p2Alive) {
        currentState = GameState::PLAYER2_WON;
        ++player2Wins;
    } else if (p1Alive && !p2Alive) {
        currentState = GameState::PLAYER1_WON;
        ++player1Wins;
    }

    ++totalGamesPlayed;
}

void BattleGame::displayStatus() const {
    std::cout << "=== Battle Status ===\n";
    std::cout << getPlayer1().getName() << " HP: " << getPlayer1().getHealth() << "\n";
    std::cout << getPlayer2().getName() << " HP: " << getPlayer2().getHealth() << "\n";
    std::cout << "===================\n";
}

void BattleGame::displayStatistics() {
    std::cout << "=== Game Statistics ===\n";
    std::cout << "Total Games Played: " << totalGamesPlayed << "\n";
    std::cout << "Total Damage Dealt: " << totalDamageDealt << "\n";
    std::cout << "Player 1 Wins: " << player1Wins << "\n";
    std::cout << "Player 2 Wins: " << player2Wins << "\n";
    std::cout << "=======================\n";
}
