// 재귀 같은 어려운 방식이 아니더라도
// 완벽한 dp가 아니더라도
// 규칙을 찾아서 해결할 수 있는 방법이 존재한다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n;
	int dp[41] = { 0,1, 1 };

	for (int i = 2; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		if (n == 0) {
			cout << 1 << " " << 0 << endl;
		}
		else if (n == 1) {
			cout << 0 << " " << 1 << endl;
		}
		else {
			cout << dp[n-1] << " " << dp[n ] << endl;
		}

	}

	return 0;
}