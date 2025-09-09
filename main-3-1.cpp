#include <iostream>
#include "Fridge.h"
#include "TV.h"
#include "House.h"
using namespace std;

int main() {
    House h(3);

    Fridge f1(150, 300);
    TV t1(120, 50);

    h.addAppliance(&f1);
    h.addAppliance(&t1);

    cout << "Total house consumption: " << h.getTotalPowerConsumption() << endl;
}
