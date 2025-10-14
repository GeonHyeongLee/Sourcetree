#include <iostream>

using namespace std;

int n;
int hp_minus[21];
int happy[21];

int dp[21][101];

int main(void) {
	cin >> n;
	// 무게
	for (int i = 1; i <= n; i++) {
		cin >> hp_minus[i];
	}
	// 가중치
	for (int i = 1; i <= n; i++) {
		cin >> happy[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 100; j++) {
			if (j >= hp_minus[i]) {
				dp[i][j] = max(dp[i - 1][j - hp_minus[i]] + happy[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][99] << "\n";

}