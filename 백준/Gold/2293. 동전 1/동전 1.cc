#include <iostream>
#include <vector>

using namespace std;

int n;
int k;

int main(void) {
	cin >> n >> k;
	vector<int> coin(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = max(dp[j], dp[j - coin[i]] + dp[j]);
		}
	}

	cout << dp[k];
}