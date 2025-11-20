#include <iostream>
#include <vector>

#define MAX 401
#define INF 987654321
using namespace std;

int V, E;

vector<vector<int>> graph(401, vector<int>(401, INF));

int main(void) {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
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

	int min_cycle = INF;

	for (int i = 1; i <= V; i++) {
		min_cycle = min(min_cycle, graph[i][i]);
	}

	if (min_cycle == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << min_cycle << "\n";
	}

}