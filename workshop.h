#ifndef WORKSHOP_H
#define WORKSHOP_H
#include <iostream>

// Part 2: changeValue(double*)
// Modifies the double value at the given memory address to 42.
inline void changeValue(double* ptr) {
    if (ptr) { *ptr = 42; }
}

// Part 3: printArray(double*, int)
// Prints the elements of an array of doubles.
inline void printArray(double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i + 1 == size ? '\n' : ' ');
    }
}

// Part 4: arrayMax(double*, int)
// Returns the maximum value in an array of doubles.
inline double arrayMax(double* arr, int size) {
    if (!arr || size <= 0) return 0.0;
    double m = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

// Part 7: dynamicArray(int, double)
// Allocates an array of size N and initializes all elements to M.
inline double* dynamicArray(int N, double M) {
    if (N <= 0) return nullptr;
    double* a = new double[N];
    for (int i = 0; i < N; ++i) a[i] = M;
    return a;
}

#endif // WORKSHOP_H
