// dp�� ���ؼ� Ǯ��� �Ѵ�.
// 0�� ����, 1�� ����, 2�� ���� ���ô� ��� �߿� ���� ū ���� ������ �ݺ��ؾ� �Ѵ�.
// ** vector�� ������ �� �� ���� push_back ���ִ� �� �ƴ� �̻� �⺻������ ũ�⸦ ó����
// ��������� �Ѵ�. vecotr<int> arr(n+1) �̷������� ** 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 1. arr�� 1-indexed�� ����
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // dp[i]: i��° �ܱ��� ���� �� �ִ� �ִ� ������ ��
    vector<int> dp(n + 1, 0);

    if (n >= 1) dp[1] = arr[1];
    if (n >= 2) dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max({
            dp[i - 1],                          // �̹� �� �� ���� ��
            dp[i - 2] + arr[i],                // 1�� ���� ���� ��
            dp[i - 3] + arr[i - 1] + arr[i]    // 2�� ���� ���� ��
            });
    }

    cout << dp[n] << "\n";
    return 0;
}