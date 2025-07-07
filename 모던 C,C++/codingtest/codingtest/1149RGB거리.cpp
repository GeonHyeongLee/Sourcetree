#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int house_color[MAX][3];

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house_color[i][j];
		}
	}

	int dp[MAX][3];

	dp[1][0] = house_color[1][0];
	dp[1][1] = house_color[1][1];
	dp[1][2] = house_color[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1] + house_color[i][0], dp[i - 1][2] + house_color[i][0]);
		dp[i][1] = min(dp[i - 1][0] + house_color[i][1], dp[i - 1][2] + house_color[i][1]);
		dp[i][2] = min(dp[i - 1][0] + house_color[i][2], dp[i - 1][1] + house_color[i][2]);
	}
	//cout << dp[1][0] << dp[1][1] << dp[1][2] <<  "\n";
	//cout << dp[2][0] << " " << dp[2][1] << " " << dp[2][2] << "\n";
	cout << min({ dp[N][0], dp[N][1], dp[N][2] });
}