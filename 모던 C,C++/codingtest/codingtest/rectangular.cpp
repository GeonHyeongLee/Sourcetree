#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

int dp[MAX][MAX];

int main() {
	int map[MAX][MAX] = { {9,6,1,5,3,7,8,5},{3,4,2,5,7,8,7,9},{8,7,7,6,4,3,5,7},{3,6,8,9,5,7,7,9},{8,7,6,2,3,5,6,8},{1,2,3,4,5,2,3,5},{9,8,7,6,8,3,4,5},{6,5,4,6,3,7,9,9} };

	dp[0][0] = map[0][0];

	for (int i = 1; i < sizeof(map[0]) / sizeof(map[0][0]); i++) {
		dp[0][i] = dp[0][i - 1] + map[0][i];
	}

	for (int i = 1; i < sizeof(map) / sizeof(map[0]); i++) {
		dp[i][0] = dp[i - 1][0] + map[i][0];
	}


	for (int i = 1; i < sizeof(map) / sizeof(map[0]); i++) {
		for (int j = 1; j < sizeof(map) / sizeof(map[0]); j++) {
			dp[i][j] = max(dp[i - 1][j] + map[i][j], dp[i][j - 1] + map[i][j]);
		}
	}

	cout << dp[7][7];

	return 0;
}