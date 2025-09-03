#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle {
public:
    explicit Motorbike(int id);
    int getParkingDuration() const override;
};

#endif
