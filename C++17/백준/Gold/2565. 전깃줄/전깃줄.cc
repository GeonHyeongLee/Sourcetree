#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;

vector<pair<int, int>> v;

int main(void) {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int st, end;
		cin >> st >> end;

		v.push_back({ st, end });
	}
	
	// 시작점 기준으로 정렬
	sort(v.begin(), v.end());

	//for (int i = 0; i < n; i++) {
	//	cout << v[i].first << " ";
	//}

	// LIS(최장 증가 부분수열) 구하기 => end 기준으로 계속해서 늘어나는 숫자 찾아서 가장
	// 오래 동안 늘어나는 거 찾으면 전체 길이 - 최장 길이 = 빼야 할 최소 개수

	
	vector<int> dp(n, 1);

	vector<int> prev_idx(n, -1);

	int best_len = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				prev_idx[i] = j;
			}
		}

		if (dp[i] > best_len) {
			best_len = dp[i];
		}
	}

	cout << n - best_len << "\n";

}