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

		int dp_up[MAX];
		int dp_down[MAX];

		dp_up[0] = stickers[0][0];
		dp_down[0] = stickers[1][0];
		dp_up[1] = dp_down[0] + stickers[0][1];
		dp_down[1] = dp_up[0] + stickers[1][1];

		for (int k = 2; k < n; k++) {
			dp_up[k] = max(dp_down[k - 1], dp_down[k - 2]) + stickers[0][k];
			dp_down[k] = max(dp_up[k - 1], dp_up[k - 2]) + stickers[1][k];
		}

		cout << max(dp_up[n - 1], dp_down[n - 1]) << "\n";
	}
}