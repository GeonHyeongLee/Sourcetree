#include <iostream>

using namespace std;

int N;

int value = 0;


// �� ������� ����ϰ� ó������
int all_sum(int n) {
    if (n == 1) {
        return 1;
    }
    return all_sum(n - 1) + n;
}

// �̷������� �ϸ� �ʹ� �޸𸮸� ���� ��Ƹ԰� �ȴ�.
int value = 0;
int all_sum(int n) {
    if (n == 0) {
        return value;
    }
    value += n;
    all_sum(n - 1);
}



int main() {
    cin >> N;
    int res = all_sum(N);
    cout << res;
    return 0;
}


