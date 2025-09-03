#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"

class Warrior : public Player {
private:
    std::string weapon;

public:
    Warrior(const std::string& name, int health, int damage, const std::string& weapon);

    void swingWeapon(Player* opponent);

    const std::string& getWeapon() const { return weapon; }
    void setWeapon(const std::string& w) { weapon = w; }
};

#endif
