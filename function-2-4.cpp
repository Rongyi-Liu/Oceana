#include <iostream>
#include <limits.h>

int array_min(int integers[], int length) {
    if (length <= 0) return -1;
    int mn = integers[0];
    for (int i = 1; i < length; ++i) {
        if (integers[i] < mn) mn = integers[i];
    }
    return mn;
}

int array_max(int integers[], int length) {
    if (length <= 0) return -1;
    int mx = integers[0];
    for (int i = 1; i < length; ++i) {
        if (integers[i] > mx) mx = integers[i];
    }
    return mx;
}

// Signature: int sum_min_max(int integers[], int length)
int sum_min_max(int integers[], int length) {
    if (length <= 0) return -1;
    int mn = array_min(integers, length);
    int mx = array_max(integers, length);
    if (mn == -1 || mx == -1) return -1; // defensive
    return mn + mx;
}
