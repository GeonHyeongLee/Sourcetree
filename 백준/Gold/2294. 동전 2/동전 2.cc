#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int n, k;


int main(void) {
	cin >> n >> k;

	vector<int> coin(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	vector<int> dp(k + 1, MAX);

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == MAX) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}

}