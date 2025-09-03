#include "Vehicle.h"
#include <ctime>

Vehicle::Vehicle(int id) : timeOfEntry(std::time(nullptr)), ID(id) {}

int Vehicle::getID() const { return ID; }
