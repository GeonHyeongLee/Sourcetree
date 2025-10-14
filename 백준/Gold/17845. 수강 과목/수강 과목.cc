#include <iostream>

#define MAX 1001
using namespace std;

int n;
int k;

int importance[MAX];
int study_t[MAX];

int dp[1001][10001];

int main(void) {
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		int im, t;
		cin >> im >> t;
		importance[i] = im;
		study_t[i] = t;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (j >= study_t[i]) {
				dp[i][j] = max(dp[i - 1][j - study_t[i]] + importance[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}


	cout << dp[k][n];

}