// ���� index�� �����ؾ� �Ѵٸ� ��� �ؾ� ���� ����� �Ǿ���
// ���� �������� �����ߴ�
// ó�� ���� ������ ���Ƿ� �ƹ��� �������� ������ ���� �ʴ� ��������
// ������ �Ǵ� ���̾���.
// ����, �̵� �ÿ� ����, �������� ��� �ؾ� ���� �򰥷ȴµ�
// ���� �׸��� �׷����� ���� �����Ͽ���.

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