#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 801
#define INF 987654321

vector<int> d(MAX, INF);
vector<pair<int, int>> graph[MAX];

int main(void) {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	int v1, v2;
	cin >> v1 >> v2;


	d[v1] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ d[v1], v1 });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int vertex = cur.second;
		int cost = cur.first;

		if (d[vertex] < cost) {
			continue;
		}

		for (int i = 0; i < graph[vertex].size(); i++) {
			int nxt_vertex = graph[vertex][i].second;
			int nxt_cost = graph[vertex][i].first;

			if (d[nxt_vertex] > d[vertex] + nxt_cost) {
				d[nxt_vertex] = d[vertex] + nxt_cost;
				pq.push({ d[nxt_vertex], nxt_vertex });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}



}