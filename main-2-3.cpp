#include <iostream>

int sum_if_palindrome(int integers[], int length);

int main() {
    int a1[] = {1,2,2,1};
    std::cout << sum_if_palindrome(a1, 4) << std::endl; // 6

    int a2[] = {1,0,2,0,1};
    std::cout << sum_if_palindrome(a2, 5) << std::endl; // 4

    int a3[] = {1,2,3};
    std::cout << sum_if_palindrome(a3, 3) << std::endl; // -2 (not palindrome)

    std::cout << sum_if_palindrome(a3, 0) << std::endl; // -1 (invalid length)
    return 0;
}
