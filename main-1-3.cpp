#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include <iostream>

int main() {
    ParkingLot lot(10);

    // Park 5 Cars, 3 Buses, 2 Motorbikes
    for (int i = 1; i <= 5; ++i) lot.parkVehicle(new Car(i));        // IDs 1..5
    for (int i = 6; i <= 8; ++i) lot.parkVehicle(new Bus(i));        // IDs 6..8
    for (int i = 9; i <= 10; ++i) lot.parkVehicle(new Motorbike(i)); // IDs 9..10

    int over = lot.countOverstayingVehicles(15);
    std::cout << over << "\n";
    return 0;
}
