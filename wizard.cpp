#include "wizard.h"
#include <iostream>

Wizard::Wizard(const std::string& n, int h, int d, int m)
    : Player(n, h, d), mana(m) {}

void Wizard::castSpell(Player* opponent) {
    if (!opponent) return;
    std::cout << name << " casts a spell on " << opponent->getName()
              << " for " << mana << " damage.\n";
    opponent->takeDamage(mana);
}
