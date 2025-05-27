// c++에서 sort를 쓸 때 vecotr라면 sort(arr.begin(), arr.end())를 사용하지만
// 배열을 sort할 때에는 sort(arr, arr + i(대상 인덱스) + 1) 까지 해줘야 한다.

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