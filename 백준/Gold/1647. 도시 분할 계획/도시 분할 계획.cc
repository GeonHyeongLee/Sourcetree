#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, M;

vector<pair<int, int>> graph[MAX];

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });

	vector<bool> visited(MAX, false);
	int edge_count = 0;
	int min_cost = 0;

	int maximum_edge = 0; // 생각해보니까 최소 스패닝 트리 구한다음에
	// 가장 큰 간선 하나만 빼면 모든 조건 만족하는거 아닌가?

	while (!pq.empty() && edge_count< N) {
		auto cur = pq.top(); pq.pop();
		int cur_w = cur.first;
		int cur_v = cur.second;

		if (visited[cur_v]) {
			continue;
		}

		visited[cur_v] = true;
		edge_count++;
		min_cost += cur_w;
		maximum_edge = max(maximum_edge, cur_w);

		for (int i = 0; i < graph[cur_v].size(); i++) {
			int nxt_w = graph[cur_v][i].first;
			int nxt_v = graph[cur_v][i].second;

			if (!visited[nxt_v]) {
				pq.push({ nxt_w, nxt_v });
			}
		}
	}



	cout << min_cost - maximum_edge;
}