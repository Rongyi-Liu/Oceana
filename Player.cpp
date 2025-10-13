#include "Player.h"

Player::Player(const std::string& name)
    : name(name), health(100), isBlocking(false) {}

void Player::takeDamage(int damage) {
    if (isBlocking) {
        damage /= 2;              // reduce by 50%
        isBlocking = false;       // only lasts for one attack
    }
    if (damage < 0) damage = 0;
    health -= damage;
    if (health < 0) health = 0;   // clamp to zero
}

void Player::setBlocking(bool blocking) {
    isBlocking = blocking;
}

bool Player::getIsBlocking() const {
    return isBlocking;
}

int Player::getHealth() const {
    return health;
}

std::string Player::getName() const {
    return name;
}

bool Player::isAlive() const {
    return health > 0;
}
