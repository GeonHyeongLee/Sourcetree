#include <iostream>
#include <vector>
using namespace std;

int n;
int m;


int main(void) {
	cin >> n >> m;

	// 메모리 = 무게
	vector<int> memory(n + 1);
	
	// 비용 = 가중치
	vector<int> cost(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}

	int all_cost = 0;

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		all_cost += cost[i];
	}

	vector<int> max_cost_memory(all_cost + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = all_cost; j >= cost[i]; j--) {
			max_cost_memory[j] = max(max_cost_memory[j], max_cost_memory[j - cost[i]] + memory[i]);
		}
	}

	int result;

	for (int i = 0; i <= all_cost; i++) {
		if (max_cost_memory[i] >= m) {
			result = i;
			break;
		}
	}

	cout << result;

}