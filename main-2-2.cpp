#include <iostream>
#include "TV.h"
using namespace std;

int main() {
    TV t1(120, 50);
    t1.turnOn();
    cout << "TV screen size: " << t1.getScreenSize() << " inches" << endl;
    cout << "TV consumption: " << t1.getPowerConsumption() << endl;
}
