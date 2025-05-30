#include <iostream>
#define MAX 100
using namespace std;

int N;
int x1[10], y1[10];
int x2[10], y2[10];


int arr[2 * MAX + 1][2 * MAX + 1];

int main() {
    cin >> N;

    int rect;

    int pt = MAX;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        for (int j = pt + x1[i]; j < pt + x2[i]; j++) {
            for (int k = pt + y1[i]; k < pt + y2[i]; k++) {
                arr[j][k] = 1;
            }
        }

    }

    int count = 0;
    for (int i = 0; i < 2 * MAX + 1; i++) {
        for (int j = 0; j < 2 * MAX + 1; j++) {
            if (arr[i][j] == 1) {
                count += 1;
            }
        }
    }

    cout << count;




    return 0;
}