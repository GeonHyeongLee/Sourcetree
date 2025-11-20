#include <iostream>
#include <vector>
#include <queue>

#define MAX 10001
#define INF 987654321

using namespace std;

int V, E;

vector<pair<int, int>> graph[MAX];

int main(void) {

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });

	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> visited_v(MAX, false);

	pq.push({ 0,1 });

	int edge_count = 0;
	int min_tree = 0;

	while (!pq.empty() && edge_count < V) {
		auto cur = pq.top(); pq.pop();
		int cur_w = cur.first;
		int cur_v = cur.second;

		if (visited_v[cur_v]) {
			continue;
		}

		visited_v[cur_v] = true;
		min_tree += cur_w;
		edge_count++;

		for (int i = 0; i < graph[cur_v].size(); i++) {
			int nxt_w = graph[cur_v][i].first;
			int nxt_v = graph[cur_v][i].second;

			if (!visited_v[nxt_v]) {
				pq.push({ nxt_w, nxt_v });
			}
		}
	}

	cout << min_tree;
}