#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main(void) {
	cin >> n >> k;

	vector<int> value(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}

	vector<int> dp(k + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = value[i]; j <= k; j++) {
			dp[j] += dp[j - value[i]];
		}
	}

	cout << dp[k];
}