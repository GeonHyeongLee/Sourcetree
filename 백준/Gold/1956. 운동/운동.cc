#include <iostream>
#include <vector>

#define MAX 401
#define INF 987654321
using namespace std;

int V, E;

vector<vector<int>> graph(MAX, vector<int>(MAX, INF));

int main(void) {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = w;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][k] != INF && graph[k][j] != INF) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}

	int minnum = INF;

	for (int i = 1; i <= V; i++) {
		if (graph[i][i] != INF) {
			minnum = min(minnum, graph[i][i]);
		}
	}

	if (minnum == INF) {
		cout << -1;
	}
	else {
		cout << minnum;
	}

}