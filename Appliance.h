#ifndef APPLIANCE_H
#define APPLIANCE_H

class Appliance {
private:
    int powerRating;
    bool isOn;

public:
    Appliance();
    Appliance(int powerRating);

    int getPowerRating() const;
    void setPowerRating(int rating);

    bool getIsOn() const;

    void turnOn();
    void turnOff();
    virtual double getPowerConsumption() const;
};

#endif
