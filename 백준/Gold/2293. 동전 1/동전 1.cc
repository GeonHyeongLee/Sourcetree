#include <iostream>
#include <vector>
using namespace std;
int n;
int k;

int main() {
	cin >> n >> k;

	vector<int> coin(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	vector<int> cost_coin(k + 1, 0);

	cost_coin[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			cost_coin[j] += cost_coin[j - coin[i]];
			//cout << cost_coin[j] << "\n";
		}
	}



	cout << cost_coin[k];

}