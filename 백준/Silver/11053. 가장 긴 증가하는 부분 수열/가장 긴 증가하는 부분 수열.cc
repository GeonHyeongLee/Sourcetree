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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int max_num = 0;
	for (int i = 0; i < n; i++) {
		max_num = max(max_num, dp[i]);
	}
	cout << max_num;
}