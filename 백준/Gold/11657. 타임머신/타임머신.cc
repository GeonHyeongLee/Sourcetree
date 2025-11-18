#include <iostream>
#include <vector>

#define INF 987654321
#define MAX 501

using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};

int N, M;

int main(void) {
	cin >> N >> M; // N : 노드 개수, M : 간선 개수

	vector<Edge> edges;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u,v,w });
	}

	long long table[MAX];

	for (int i = 0; i < MAX; i++) {
		table[i] = INF;
	}

	table[1] = 0; // start_point = 1번

	for (int i = 1; i <= N - 1; i++) {
		for (const auto& edge : edges) {
			int u = edge.from;
			int v = edge.to;
			int weight = edge.cost;

			if (table[u] != INF && table[v] > table[u] + weight) {
				table[v] = table[u] + weight;
			}
		}
	}

	bool minuscycle = false;

	for (const auto& edge : edges) {
		int u = edge.from;
		int v = edge.to;
		int weight = edge.cost;

		if (table[u] != INF && table[v] > table[u] + weight) {
			minuscycle = true;
			break;
		}
	}

	if (minuscycle) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (table[i] == INF) {
				cout << -1 << "\n";
			}
			else {
				cout << table[i] << "\n";
			}
		}
	}
}