#include "TV.h"

TV::TV() : Appliance(), screenSize(0.0) {}
TV::TV(int rating, double size) : Appliance(rating), screenSize(size) {}

void TV::setScreenSize(double size) { screenSize = size; }
double TV::getScreenSize() const { return screenSize; }

double TV::getPowerConsumption() const {
    return getPowerRating() * (screenSize / 10.0);
}
