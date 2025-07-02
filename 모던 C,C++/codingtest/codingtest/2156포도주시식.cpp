// dp를 통해서 풀어야 한다.
// 0잔 연속, 1잔 연속, 2잔 연속 마시는 경우 중에 가장 큰 값의 선택을 반복해야 한다.
// ** vector문 선언을 할 때 값을 push_back 해주는 게 아닌 이상 기본적으로 크기를 처음에
// 설정해줘야 한다. vecotr<int> arr(n+1) 이런식으로 ** 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 1. arr를 1-indexed로 선언
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // dp[i]: i번째 잔까지 마실 수 있는 최대 포도주 양
    vector<int> dp(n + 1, 0);

    if (n >= 1) dp[1] = arr[1];
    if (n >= 2) dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max({
            dp[i - 1],                          // 이번 잔 안 마실 때
            dp[i - 2] + arr[i],                // 1잔 연속 마실 때
            dp[i - 3] + arr[i - 1] + arr[i]    // 2잔 연속 마실 때
            });
    }

    cout << dp[n] << "\n";
    return 0;
}