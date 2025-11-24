#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 가수의 수
int M; // 보조 PD의 수

int main(void) {
	cin >> N >> M;

	vector<vector<int>> singers(N);
	vector<int> in_degree(N, 0);

	for (int i = 0; i < M; i++) {
		int singer;
		int first;
		
		cin >> singer >> first;

		first -= 1;

		for (int j = 0; j < singer - 1; j++) {
			int num;
			cin >> num;

			num -= 1;
			singers[first].push_back(num);
			in_degree[num] += 1;
			first = num;
		}
	}

	queue<int> q;
	
	for (int i = 0; i < N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> result;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (in_degree[cur] == 0) {
			result.push_back(cur);
		}

		for (int i = 0; i < singers[cur].size(); i++) {
			int nxt = singers[cur][i];
			
			in_degree[nxt] -= 1;

			if (in_degree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	if (result.size() != N) {
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] + 1 << "\n";
		}
	}
}