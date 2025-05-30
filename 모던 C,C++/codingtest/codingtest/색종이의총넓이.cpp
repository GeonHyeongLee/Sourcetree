#include <iostream>
#define MAX 100
using namespace std;

int N;
int x[100], y[100];

int arr[2 * MAX + 1][2 * MAX + 1];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];

        int pt = MAX;

        for (int j = (pt + x[i]); j < (pt + x[i] + 8); j++) {
            for (int k = (pt + y[i]); k < (pt + y[i] + 8); k++) {
                arr[j][k] = 1;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < 2 * MAX + 1; i++) {
        for (int j = 0; j < 2 * MAX + 1; j++) {
            if (arr[i][j] == 1) {
                count++;
            }
        }
    }

    cout << count;
    // Please write your code here.

    return 0;
}