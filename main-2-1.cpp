#include <iostream>
#include <string>

void print_binary_str(std::string decimal_number);

int main() {
    // Example runs
    print_binary_str("13");      // expected 1101
    print_binary_str("0");       // expected 0
    print_binary_str("789");     // prints binary of 789
    return 0;
}
