#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1010
#define INF 987654321
int main(void) {
	int n;
	int m;
	cin >> n;
	cin >> m;

	vector<pair<int, int>> graph[MAX];

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({ w,y });
	}

	int st, end;
	cin >> st >> end;

	vector<int> d(MAX + 1, INF);
	d[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		int cost = cur.first;
		int vertex = cur.second;

		if (d[vertex] < cost) {
			continue;
		}
		for (int i = 0; i < graph[vertex].size(); i++) {
			int cost_nxt = graph[vertex][i].first;
			int vertex_nxt = graph[vertex][i].second;

			if (d[vertex_nxt] > d[vertex] + cost_nxt) {
				d[vertex_nxt] = d[vertex] + cost_nxt;
				pq.push({ d[vertex_nxt], vertex_nxt });
			}
		}
	}

	cout << d[end] << "\n";


}