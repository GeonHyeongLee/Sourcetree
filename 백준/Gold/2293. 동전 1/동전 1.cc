#include <iostream>
#include <vector>
using namespace std;

int n;
int k;

int main(void) {
	cin >> n >> k;

	vector<int> coin(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	vector<int> cnt(k + 1, 0);

	cnt[0] = 1; // 젤 중요 아무 동전도 선택하지 않았을 때

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			cnt[j] += cnt[j - coin[i]];
		}
	}

	cout << cnt[k];
}