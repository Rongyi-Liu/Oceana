#ifndef WIZARD_H
#define WIZARD_H

#include "player.h"

class Wizard : public Player {
private:
    int mana;

public:
    Wizard(const std::string& name, int health, int damage, int mana);

    void castSpell(Player* opponent);

    int getMana() const { return mana; }
    void setMana(int m) { mana = m; }
};

#endif
