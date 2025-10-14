#include <iostream>
#include <vector>
using namespace std;

int n;
long long int m;
int main(void) {
	cin >> n >> m;

	vector<int> memory(n + 1);
	vector<int> cost(n + 1);

	int all_cost = 0;

	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		all_cost += cost[i];
	}

	// cost 당 채울 수 있는 최대 메모리 수
	vector<long long int> app_cost(all_cost + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = all_cost; j >= cost[i]; j--) {
			app_cost[j] = max(app_cost[j], app_cost[j - cost[i]] + memory[i]);
		}
	}

	//for (int i = 0; i <= all_cost; i++) {
	//	cout << app_cost[i] << " ";
	//}

	int result = 0;
	for (int i = 0; i <= all_cost; i++) {
		if (app_cost[i] >= m) {
			result = i;
			break;
		}
	}
	cout << result;

}