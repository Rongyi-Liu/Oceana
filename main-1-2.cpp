#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include <iostream>

int main() {
    ParkingLot lot(10);
    std::cout << "Parking vehicles until lot is full...\n";
    while (lot.getCount() < 10) {
        int type, id;
        std::cout << "Enter type (1=Car, 2=Bus, 3=Motorbike) and ID: ";
        if (!(std::cin >> type >> id)) return 0;
        if (type == 1) lot.parkVehicle(new Car(id));
        else if (type == 2) lot.parkVehicle(new Bus(id));
        else if (type == 3) lot.parkVehicle(new Motorbike(id));
        else std::cout << "Invalid type\n";
    }

    int removeID;
    std::cout << "Enter ID to unpark: ";
    std::cin >> removeID;
    lot.unparkVehicle(removeID);
    return 0;
}
