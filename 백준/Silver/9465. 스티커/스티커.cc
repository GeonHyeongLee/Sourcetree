#include <iostream>

#define MAX 100001
using namespace std;

int t;

int n;
int stickers[2][MAX];


int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int p = 0; p < 2; p++) {
			for (int q = 0; q < n; q++) {
				cin >> stickers[p][q];
			}
		}

		// dp를 윗열, 아랫열로 두 개로 나눈다.
		int dp_up[MAX];
		int dp_down[MAX];

		dp_up[0] = stickers[0][0];
		dp_down[0] = stickers[1][0];

		dp_up[1] = dp_down[0] + stickers[0][1];
		dp_down[1] = dp_up[0] + stickers[1][1];

		for (int p = 2; p< n; p++) {
			dp_up[p] = max(dp_down[p - 1], dp_down[p - 2]) + stickers[0][p];
			dp_down[p] = max(dp_up[p - 1], dp_up[p - 2]) + stickers[1][p];
		}

		cout << max(dp_up[n - 1], dp_down[n - 1]) << "\n";
	}
}