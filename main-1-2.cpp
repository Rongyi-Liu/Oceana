#include <iostream>
using namespace std;
int is_identity(int array[10][10]);
int main() {
    int matrix[10][10] = {0};
    for (int i = 0; i < 10; i++) matrix[i][i] = 1;
    cout << "Is identity? " << is_identity(matrix) << endl;
    return 0;
}