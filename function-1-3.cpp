#include <iostream>
using namespace std;
void count_digits(int array[4][4]) {
    int count[10] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (array[i][j] >= 0 && array[i][j] <= 9)
                count[array[i][j]]++;
        }
    }
    for (int k = 0; k < 10; k++) {
        cout << k << ":" << count[k] << ";";
    }
    cout << endl;
}