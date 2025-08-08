#include <iostream>

int binary_to_int(int binary_digits[], int number_of_digits);

int main() {
    int b1[] = {1, 1, 0, 1}; // 13
    std::cout << binary_to_int(b1, 4) << std::endl;

    int b2[] = {1,0,1,1,1,0,1,1,1}; // 0b101110111 = 375
    std::cout << binary_to_int(b2, 9) << std::endl;

    return 0;
}
