#include "wizard.h"
#include "warrior.h"
#include <iostream>

int main() {
    Wizard wizard("Merlin", 50, 5, 15);
    Warrior warrior("Conan", 60, 10, "sword");

    std::cout << "Battle begins!\n";

    while (wizard.getHealth() > 0 && warrior.getHealth() > 0) {
        wizard.castSpell(&warrior);
        if (warrior.getHealth() <= 0) break;

        warrior.swingWeapon(&wizard);
        if (wizard.getHealth() <= 0) break;
    }

    if (wizard.getHealth() > 0)
        std::cout << wizard.getName() << " wins!\n";
    else
        std::cout << warrior.getName() << " wins!\n";

    return 0;
}
