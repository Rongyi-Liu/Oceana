#include "player.h"
#include <iostream>

Player::Player(const std::string& n, int h, int d)
    : name(n), health(h), damage(d) {}

void Player::attack(Player* opponent, int dmg) {
    if (!opponent) return;
    std::cout << name << " attacks " << opponent->getName()
              << " for " << dmg << " damage.\n";
    opponent->takeDamage(dmg);
}

void Player::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    std::cout << name << " takes " << dmg
              << " damage. Remaining health: " << health << "\n";
}
