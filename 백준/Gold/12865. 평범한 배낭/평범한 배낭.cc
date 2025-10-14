#include <iostream>
#include <unordered_map>
#include <algorithm>

#define MAX 100001

using namespace std;

int n;
int k;


int weight[MAX];
int value[MAX];

int dp[101][MAX];

int main(void) {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= weight[i]) {
				dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		}
	}
	cout << dp[n][k];

}