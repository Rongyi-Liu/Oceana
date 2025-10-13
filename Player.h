#pragma once
#include <string>

class Player {
private:
    std::string name;
    int health;
    bool isBlocking;
public:
    // Constructor
    explicit Player(const std::string& name);

    // Core actions / queries
    void takeDamage(int damage);
    void setBlocking(bool blocking);
    bool getIsBlocking() const;
    int getHealth() const;
    std::string getName() const;
    bool isAlive() const;
};
