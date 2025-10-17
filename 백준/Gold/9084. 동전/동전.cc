#include <iostream>
#include <vector>

using namespace std;

int t; // 테스트 케이스 개수
int n; // 동전의 가지 수
int m; // 동전으로 만들어야 할 금액

int main(void) {
	cin >> t;
	
	for (int i = 0; i < t; i++) {

		cin >> n;
		vector<int> coins(n + 1);
		for (int j = 1; j <= n; j++) {
			cin >> coins[j];
		}

		cin >> m;

		vector<int> dp(m + 1, 0);

		dp[0] = 1;

		for (int p = 1; p <= n; p++) {
			for (int q = coins[p]; q <= m; q++) {
				dp[q] += dp[q - coins[p]];
			}
		}

		cout << dp[m] << "\n";
	}
}