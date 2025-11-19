#include <iostream>
#include <vector>

#define INF 987654321
#define MAX 501

using namespace std;

int N;
int M;

struct Edge {
	int from;
	int to;
	int cost;
};

int main(void) {

	vector<Edge> edges;
	long long table[MAX];

	for (int i = 0; i < MAX;i++) {
		table[i] = INF;
	}

	table[1] = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u,v,w });
	}

	for (int i = 1; i <= N; i++) {
		for (auto const& edge : edges) {
			int u = edge.from;
			int v = edge.to;
			int w = edge.cost;

			if (table[u] != INF && table[v] > table[u] + w) {
				table[v] = table[u] + w;
			}
		}
	}

	bool minus_chain = false;

	for (auto const& edge : edges) {
		int u = edge.from;
		int v = edge.to;
		int w = edge.cost;

		if (table[u] != INF && table[v] > table[u] + w) {
			minus_chain = true;
			break;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (minus_chain) {
			cout << -1;
			break;
		}
		else {
			if (table[i] == INF) {
				cout << -1 << "\n";
			}
			else {
				cout << table[i] << "\n";
			}
		}
	}
}