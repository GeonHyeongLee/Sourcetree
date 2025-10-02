#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int n;
vector<pair<int, int>> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
		});

	int cnt = 0;
	int last_end = 0;
	for (int i = 0; i < v.size(); i++) {
		int st = v[i].first;
		int end = v[i].second;

		if (st >= last_end) {
			cnt++;
			last_end = end;
		}
	}

	cout << cnt;
}