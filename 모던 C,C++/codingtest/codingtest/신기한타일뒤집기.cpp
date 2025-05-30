// Èò°Ë Ä¥ÇÏ±â Ç®°í ³ª´Ï ¾î·ÆÁö ¾Ê¾Ò´Ù

#include <iostream>

#define MAX 100000

using namespace std;

int n;
int x[1000];
char dir[1000];

int arr[2 * MAX + 1];


int main() {
    cin >> n;

    int pt = MAX;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];

        if (dir[i] == 'L') {
            while (x[i]--) {
                arr[pt] = 1;

                if (x[i]) {
                    pt--;
                }
            }
        }
        else {
            while (x[i]--) {
                arr[pt] = 2;

                if (x[i]) {
                    pt++;
                }
            }
        }
    }

    int b_cnt = 0;
    int w_cnt = 0;
    for (int i = 0; i < 2 * MAX; i++) {
        if (arr[i] == 1) {
            w_cnt += 1;
        }
        else if (arr[i] == 2) {
            b_cnt += 1;
        }
    }
    // Please write your code here.
    cout << w_cnt << " " << b_cnt << endl;
    return 0;
}