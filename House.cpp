#include "House.h"

House::House() : appliances(nullptr), numAppliances(0), capacity(0) {}
House::House(int cap) : numAppliances(0), capacity(cap) {
    appliances = new Appliance*[capacity];
}
House::~House() { delete[] appliances; }

bool House::addAppliance(Appliance* appliance) {
    if (numAppliances < capacity) {
        appliances[numAppliances++] = appliance;
        return true;
    }
    return false;
}

double House::getTotalPowerConsumption() const {
    double total = 0;
    for (int i = 0; i < numAppliances; i++) {
        total += appliances[i]->getPowerConsumption();
    }
    return total;
}
