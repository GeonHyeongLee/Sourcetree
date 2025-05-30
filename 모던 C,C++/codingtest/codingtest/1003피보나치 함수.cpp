// ��� ���� ����� ����� �ƴϴ���
// �Ϻ��� dp�� �ƴϴ���
// ��Ģ�� ã�Ƽ� �ذ��� �� �ִ� ����� �����Ѵ�.


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