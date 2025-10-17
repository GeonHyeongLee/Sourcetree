#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {

	cin >> n;

	vector<int> A(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<int> dp(n + 1, 1);
	vector<int> prev(n + 1, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}

	int max_len = 0;
	int last_idx = 0;

	for (int i = 0; i < n; i++) {
		if (dp[i] > max_len) {
			max_len = dp[i];
			last_idx = i;
		}
	}

	vector<int> lis;

	while (last_idx != -1) {
		lis.push_back(A[last_idx]);
		last_idx = prev[last_idx];
	}

	reverse(lis.begin(), lis.end());

	cout << max_len << "\n";
	for (int i = 0; i < lis.size(); i++) {
		cout << lis[i] << " ";
	}
}