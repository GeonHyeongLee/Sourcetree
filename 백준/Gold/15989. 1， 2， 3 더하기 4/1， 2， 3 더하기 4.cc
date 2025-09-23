#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> dp(10001, 0);

int main(void) {

	cin >> t;

	dp[0] = 1;
	
	int coins[3] = { 1,2,3 };

	for (int c : coins) {
		for (int j = c; j < 10001; j++) {
			dp[j] += dp[j - c];
		}
	}


	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}