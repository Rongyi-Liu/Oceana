#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"

class ParkingLot {
private:
    Vehicle** vehicles;
    int capacity;
    int count;

public:
    explicit ParkingLot(int maxCapacity);
    ~ParkingLot();

    bool parkVehicle(Vehicle* v);          // prints "The lot is full" if no space
    bool unparkVehicle(int id);            // prints "Vehicle not in the lot" if absent
    int getCount() const;
    int countOverstayingVehicles(int maxParkingDuration) const;
};

#endif
