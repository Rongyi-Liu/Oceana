#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter number of vehicles: ";
    if (!(std::cin >> n) || n <= 0) return 0;

    std::vector<Vehicle*> vehicles;
    vehicles.reserve(n);

    for (int i = 0; i < n; ++i) {
        int type;
        std::cout << "Enter type for vehicle " << (i+1) << " (1=Car, 2=Bus, 3=Motorbike): ";
        std::cin >> type;
        if (type == 1) vehicles.push_back(new Car(i+1));
        else if (type == 2) vehicles.push_back(new Bus(i+1));
        else if (type == 3) vehicles.push_back(new Motorbike(i+1));
        else std::cout << "Invalid type, skipping...\n";
    }

    std::cout << "\nParking durations (seconds):\n";
    for (auto* v : vehicles) {
        std::cout << "Vehicle ID " << v->getID() << ": " << v->getParkingDuration() << "\n";
    }

    for (auto* v : vehicles) delete v;
    return 0;
}
