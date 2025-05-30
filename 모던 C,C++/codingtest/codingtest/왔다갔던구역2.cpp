// 음수 index를 접근해야 한다면 어떻게 해야 할지 고민이 되었다
// 답은 생각보다 간단했다
// 처음 시작 지점을 임의로 아무리 내려가도 음수가 되지 않는 지점으로
// 잡으면 되는 것이었다.
// 또한, 이동 시에 포함, 불포함을 어떻게 해야 할지 헷갈렸는데
// 직접 그림을 그려보는 것이 유용하였다.

#include <iostream>

using namespace std;

int n;
int x[100];
char dir[100];

int arr[2000];

int main() {
    cin >> n;
    int cur_pt = 1000;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];

        if (dir[i] == 'R') {
            for (int j = cur_pt; j < cur_pt + x[i]; j++) {
                arr[j] += 1;

            }
            cur_pt = cur_pt + x[i];
        }
        else if (dir[i] == 'L') {
            for (int j = cur_pt - x[i]; j < cur_pt; j++) {
                arr[j] += 1;
            }
            cur_pt = cur_pt - x[i];
        }
    }
    int count = 0;

    for (int i = 0; i < 2000; i++) {
        if (arr[i] >= 2) {
            count++;
        }
    }
    cout << count;
    // Please write your code here.

    return 0;
}