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
	vector<int> prev(n + 1, -1); // 경로 추적을 위한 직전 인덱스 저장

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dp[j] + 1 > dp[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
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

	//cout << "max_len : " << max_len << "\n";

	//cout << "last_idx : " << last_idx << "\n";

	// last_idx는 prev에 들어가서 가장 마지막 idx가 누군지 계속 반환해줘야된다

	vector<int> lis;
	while (last_idx != -1) {
		lis.push_back(A[last_idx]); // A[last_dx]값이 들어가줘야 할 것
		last_idx = prev[last_idx]; // 그 다음 다시 idx 다음 값으로 돌려줌
	}

	reverse(lis.begin(), lis.end());

	cout << max_len << "\n";
	for (int i = 0; i < lis.size(); i++) {
		cout << lis[i] << " ";
	}
}