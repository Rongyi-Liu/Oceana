#include <iostream>
#include "Fridge.h"
using namespace std;

int main() {
    Fridge f1(150, 300);
    f1.turnOn();
    cout << "Fridge volume: " << f1.getVolume() << "L" << endl;
    cout << "Fridge consumption: " << f1.getPowerConsumption() << endl;
}
