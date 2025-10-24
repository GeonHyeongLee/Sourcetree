#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;

// vector<vector<int>>는 바깥 벡터의 크기가 존재해야 안쪽 push_back이 가능하다
vector<int> graph[1001];

bool visited[1001];

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {
		auto x = q.front(); q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i];
			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
			}
		}
	}
}
int main(void) {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// graph = {{}, {2,5},{1,5},{4,6},{3,6},{1,2},{3,4}};
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;

}