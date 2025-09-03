#include "ParkingLot.h"
#include "Vehicle.h"
#include <iostream>

ParkingLot::ParkingLot(int maxCapacity)
    : capacity(maxCapacity), count(0) {
    vehicles = new Vehicle*[capacity];
    for (int i = 0; i < capacity; ++i) vehicles[i] = nullptr;
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < capacity; ++i) {
        delete vehicles[i];
        vehicles[i] = nullptr;
    }
    delete[] vehicles;
}

bool ParkingLot::parkVehicle(Vehicle* v) {
    if (count >= capacity) {
        std::cout << "The lot is full\n";
        delete v; // avoid leak since caller attempted to park a new vehicle
        return false;
    }
    for (int i = 0; i < capacity; ++i) {
        if (vehicles[i] == nullptr) {
            vehicles[i] = v;
            ++count;
            return true;
        }
    }
    // Shouldn't reach here, but safeguard
    std::cout << "The lot is full\n";
    delete v;
    return false;
}

bool ParkingLot::unparkVehicle(int id) {
    for (int i = 0; i < capacity; ++i) {
        if (vehicles[i] && vehicles[i]->getID() == id) {
            delete vehicles[i];
            vehicles[i] = nullptr;
            --count;
            return true;
        }
    }
    std::cout << "Vehicle not in the lot\n";
    return false;
}

int ParkingLot::getCount() const { return count; }

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int over = 0;
    for (int i = 0; i < capacity; ++i) {
        if (vehicles[i] && vehicles[i]->getParkingDuration() > maxParkingDuration) {
            ++over;
        }
    }
    return over;
}
