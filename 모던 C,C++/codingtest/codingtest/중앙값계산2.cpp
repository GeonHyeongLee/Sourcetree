// c++���� sort�� �� �� vecotr��� sort(arr.begin(), arr.end())�� ���������
// �迭�� sort�� ������ sort(arr, arr + i(��� �ε���) + 1) ���� ����� �Ѵ�.

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tmp[100];

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sort(arr, arr + i + 1);
            int arr_mid = (i / 2);
            cout << arr[arr_mid] << " ";
        }
    }

    return 0;
}