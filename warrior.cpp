#include "warrior.h"
#include <iostream>

Warrior::Warrior(const std::string& n, int h, int d, const std::string& w)
    : Player(n, h, d), weapon(w) {}

void Warrior::swingWeapon(Player* opponent) {
    if (!opponent) return;
    std::cout << name << " swings their " << weapon
              << " at " << opponent->getName() << "!\n";
    opponent->takeDamage(damage);
}
