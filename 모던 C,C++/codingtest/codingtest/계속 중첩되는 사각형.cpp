#include <iostream>
#define MAX 100
using namespace std;

int n;
int x1[10], y1[10];
int x2[10], y2[10];

int arr[2 * MAX + 1][2 * MAX + 1];

int main() {
    cin >> n;

    int pt = MAX;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        if (i % 2 == 0) {
            for (int j = pt + x1[i]; j < pt + x2[i]; j++) {
                for (int k = pt + y1[i]; k < pt + y2[i]; k++) {
                    arr[j][k] = 1; // 빨간색 = 1
                }
            }
        }
        else {
            for (int j = pt + x1[i]; j < pt + x2[i]; j++) {
                for (int k = pt + y1[i]; k < pt + y2[i]; k++) {
                    arr[j][k] = 2; // 파란색 = 2
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 2 * MAX + 1; i++) {
        for (int j = 0; j < 2 * MAX + 1; j++) {
            if (arr[i][j] == 2) {
                count++;
            }
        }
    }

    cout << count;
    // Please write your code here.

    return 0;
}