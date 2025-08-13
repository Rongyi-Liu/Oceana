#include <iostream>
#include "workshop.h"

int main() {
    // Part 2 demo
    double x = 10.0;
    changeValue(&x);
    std::cout << "After changeValue: " << x << std::endl;

    // Part 3 & 4 demo
    double a[5] = {1.5, 3.2, 4.8, 2.9, 0.5};
    std::cout << "Array: ";
    printArray(a, 5);
    std::cout << "Max: " << arrayMax(a, 5) << std::endl;

    // Part 7 demo
    int N = 4; double M = 7.5;
    double* d = dynamicArray(N, M);
    std::cout << "Dynamic: ";
    printArray(d, N);
    std::cout << "Max(dynamic): " << arrayMax(d, N) << std::endl;
    delete[] d;

    return 0;
}
