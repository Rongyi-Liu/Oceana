#include <iostream>

int sum_min_max(int integers[], int length);

int main() {
    int a[] = {3, -1, 5, 7, 2};
    std::cout << sum_min_max(a, 5) << std::endl; // -1 + 7 = 6

    int b[] = {42};
    std::cout << sum_min_max(b, 1) << std::endl; // 84

    std::cout << sum_min_max(b, 0) << std::endl; // -1 (invalid)
    return 0;
}
