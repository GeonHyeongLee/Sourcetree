#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

int n;
int k;

int main(void) {
	cin >> n >> k;

	vector<int> coin(n + 1);

	int all_coin = 0;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	vector<int> result(k + 1, MAX);

	result[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			result[j] = min(result[j], result[j - coin[i]] + 1);
			//cout << result[j] << " ";
		}
	}

	if (result[k] == MAX) {
		cout << -1;
	}
	else {
		cout << result[k];
	}

	

}