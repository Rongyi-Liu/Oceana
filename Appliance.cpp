#include "Appliance.h"

Appliance::Appliance() : powerRating(0), isOn(false) {}
Appliance::Appliance(int rating) : powerRating(rating), isOn(false) {}

int Appliance::getPowerRating() const { return powerRating; }
void Appliance::setPowerRating(int rating) { powerRating = rating; }

bool Appliance::getIsOn() const { return isOn; }

void Appliance::turnOn() { isOn = true; }
void Appliance::turnOff() { isOn = false; }

double Appliance::getPowerConsumption() const { return 0.0; }
