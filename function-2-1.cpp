#include <iostream>
#include <string>

// Signature: void print_binary_str(std::string decimal_number)
void print_binary_str(std::string decimal_number) {
    // Convert string to integer (assume 0..999,999,999 per spec)
    // Handle leading zeros safely.
    long long n = 0;
    for (char c : decimal_number) {
        if (c >= '0' && c <= '9') {
            n = n * 10 + (c - '0');
        } else {
            // Non-digit shouldn't occur by spec; treat as zero.
        }
    }
    // Special case 0
    if (n == 0) {
        std::cout << "0\n";
        return;
    }
    // Build binary in reverse
    std::string bits;
    while (n > 0) {
        bits.push_back( (n % 2) ? '1' : '0');
        n /= 2;
    }
    // Reverse to correct order
    for (int i = (int)bits.size() - 1; i >= 0; --i) {
        std::cout << bits[i];
    }
    std::cout << "\n";
}
