#include <iostream>
#define MAX 1000

using namespace std;

int x1[3], y1[3];
int x2[3], y2[3];

int arr[2 * MAX + 1][2 * MAX + 1];


int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];

    int pt = MAX;
    int count = 0;

    for (int i = x1[0] + pt; i < x2[0] + pt; i++) {
        for (int j = y1[0] + pt; j < y2[0] + pt; j++) {
            arr[i][j] = 1;
        }
    }

    for (int i = x1[1] + pt; i < x2[1] + pt; i++) {
        for (int j = y1[1] + pt; j < y2[1] + pt; j++) {
            arr[i][j] = 1;
        }
    }

    for (int i = x1[2] + pt; i < x2[2] + pt; i++) {
        for (int j = y1[2] + pt; j < y2[2] + pt; j++) {
            arr[i][j] = 0;
        }
    }

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