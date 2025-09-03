#include "Car.h"
#include <ctime>

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(difftime(now, timeOfEntry));
    return static_cast<int>(duration * 0.90); // 10% reduction
}
