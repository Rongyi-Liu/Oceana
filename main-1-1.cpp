#include <iostream>
#include "Appliance.h"
using namespace std;

int main() {
    Appliance a1;
    Appliance a2(150);

    a1.turnOn();
    cout << "Appliance 1 is on? " << a1.getIsOn() << endl;
    cout << "Appliance 2 power rating: " << a2.getPowerRating() << endl;
    cout << "Appliance 2 consumption: " << a2.getPowerConsumption() << endl;
}
