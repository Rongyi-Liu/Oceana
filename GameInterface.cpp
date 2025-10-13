#include "GameInterface.h"
#include <iostream>
#include <limits>

static ActionType toAction(int n) {
    switch (n) {
        case 1: return ActionType::LIGHTATTACK;
        case 2: return ActionType::HEAVYATTACK;
        default: return ActionType::BLOCK;
    }
}

void GameInterface::displayWelcome() {
    std::cout << "WELCOME TO BATTLE SIMULATOR\n";
    std::cout << "Rules: On your turn choose 1) Light Attack (15 dmg), "
                 "2) Heavy Attack (30 dmg), 3) Block (half next damage).\n\n";
}

void GameInterface::displayGoodbye() {
    std::cout << "Thanks for playing!\n";
}

ActionType GameInterface::getPlayerAction(const std::string& who) {
    int choice = 0;
    while (true) {
        std::cout << who << "'s turn\n";
        std::cout << "Choose your action: [1] Light  [2] Heavy  [3] Block -> ";
        if (std::cin >> choice && choice >= 1 && choice <= 3) break;
        std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return toAction(choice);
}

void GameInterface::displayTurnResult(ActionType p1, ActionType p2) {
    auto show = [](ActionType a) {
        switch (a) {
            case ActionType::LIGHTATTACK: return "Light Attack";
            case ActionType::HEAVYATTACK: return "Heavy Attack";
            case ActionType::BLOCK:       return "Block";
        }
        return "Unknown";
    };
    std::cout << "\n--- Turn Result ---\n";
    std::cout << "Player 1 used: " << show(p1) << "\n";
    std::cout << "Player 2 used: " << show(p2) << "\n";
    std::cout << "-------------------\n\n";
}

void GameInterface::displayWinner(GameState state) {
    std::cout << "GAME OVER!\n";
    switch (state) {
        case GameState::PLAYER1_WON: std::cout << "Player 1 WINS!\n\n"; break;
        case GameState::PLAYER2_WON: std::cout << "Player 2 WINS!\n\n"; break;
        case GameState::DRAW:        std::cout << "It's a DRAW!\n\n";   break;
        default: break;
    }
}

bool GameInterface::promptPlayAgain() {
    std::cout << "Play again? (y/n): ";
    char c = 'n';
    std::cin >> c;
    return c == 'y' || c == 'Y';
}
