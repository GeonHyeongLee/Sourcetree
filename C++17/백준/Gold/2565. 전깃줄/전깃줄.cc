#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int st, end;
		cin >> st >> end;
		v.push_back({ st, end });
	}

	sort(v.begin(), v.end());


	vector<int> dp(n, 1);

	int max_num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_num = max(max_num, dp[i]);
	}

	cout << n - max_num;
}