#include "Fridge.h"

Fridge::Fridge() : Appliance(), volume(0.0) {}
Fridge::Fridge(int rating, double vol) : Appliance(rating), volume(vol) {}

void Fridge::setVolume(double v) { volume = v; }
double Fridge::getVolume() const { return volume; }

double Fridge::getPowerConsumption() const {
    return getPowerRating() * 24 * (volume / 100.0);
}
