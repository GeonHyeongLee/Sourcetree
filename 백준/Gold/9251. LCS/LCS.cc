#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s1;
string s2;

int main(void) {
	cin >> s1;
	cin >> s2;

	int s1_len = s1.size();
	int s2_len = s2.size();

	vector<vector<int>> dp(s1_len + 1, vector<int>(s2_len + 1, 0));

	for (int i = 1; i <= s1_len; i++) {
		for (int j = 1; j <= s2_len; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1_len][s2_len];
}