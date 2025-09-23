#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;

		vector<int> dp(num + 1, 0);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int j = 4; j <= num; j++) {
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]);
		}

		cout << dp[num] << "\n";
	}
}