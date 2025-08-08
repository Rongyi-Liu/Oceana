#include <iostream>

// Signature: int binary_to_int(int binary_digits[], int number_of_digits)
// Assumes MSB at index 0, LSB at index number_of_digits-1
int binary_to_int(int binary_digits[], int number_of_digits) {
    if (number_of_digits < 1 || number_of_digits > 30) return 0; // basic guard
    int value = 0;
    for (int i = 0; i < number_of_digits; ++i) {
        value = (value << 1) + (binary_digits[i] ? 1 : 0);
    }
    return value;
}
