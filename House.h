#ifndef HOUSE_H
#define HOUSE_H

#include "Appliance.h"

class House {
private:
    Appliance** appliances;
    int numAppliances;
    int capacity;

public:
    House();
    House(int numAppliances);
    ~House();

    bool addAppliance(Appliance* appliance);
    double getTotalPowerConsumption() const;
};

#endif
