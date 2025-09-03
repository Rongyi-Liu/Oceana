#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    int health;
    int damage;

public:
    Player(const std::string& name, int health, int damage);

    void attack(Player* opponent, int dmg);
    void takeDamage(int dmg);

    // getters and setters
    const std::string& getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    int getHealth() const { return health; }
    void setHealth(int h) { health = h; }

    int getDamage() const { return damage; }
    void setDamage(int d) { damage = d; }

    virtual ~Player() = default;
};

#endif
