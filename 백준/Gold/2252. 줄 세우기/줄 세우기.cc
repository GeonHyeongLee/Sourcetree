#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M;

int main(void) {
	cin >> N >> M;

	vector<vector<int>> student(N);
	vector<int> in_degree(N, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		student[a].push_back(b);
		in_degree[b] += 1;
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

		result.push_back(cur);

		for (int i = 0; i < student[cur].size(); i++) {
			int nxt = student[cur][i];
			in_degree[nxt] -= 1;
			if (in_degree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	if (result.size() != N) {
		cout << "There is Cycle";
	}

	for (auto res : result) {
		cout << res+ 1 << " ";
	}
}