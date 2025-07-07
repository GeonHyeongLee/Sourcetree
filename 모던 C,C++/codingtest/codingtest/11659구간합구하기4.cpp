#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N + 1, 0);
	int dp[MAX];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++) {
		int st, end;
		cin >> st >> end;
		//cout << dp[end] << " " << dp[st - 1] << "\n";
		cout << dp[end] - dp[st - 1] << "\n";

	}
}