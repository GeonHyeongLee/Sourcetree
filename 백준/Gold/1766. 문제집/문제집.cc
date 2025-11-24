#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 문제의 수
int M; // 먼저 풀면 좋을 문제 수

int main(void) {
	cin >> N >> M;

	vector<vector<int>> problems(N);
	vector<int> in_degree(N, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		problems[a].push_back(b);
		in_degree[b] += 1;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		if (in_degree[i] == 0) {
			pq.push(i);
		}
	}

	vector<int> result;

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();

		if (in_degree[cur] == 0) {
			result.push_back(cur);
		}

		for (int i = 0; i < problems[cur].size(); i++) {
			int nxt = problems[cur][i];
			in_degree[nxt] -= 1;
			if (in_degree[nxt] == 0) {
				pq.push(nxt);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] + 1 << " ";
	}


}