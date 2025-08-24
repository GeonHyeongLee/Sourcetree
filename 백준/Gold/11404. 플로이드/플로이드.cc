#include <iostream>
#include <vector>

#define INF 987654321


using namespace std;

int n; // 정점 개수
int m; // 간선 개수



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> m;
	
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));


	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int st, end, w;
		cin >> st >> end >> w;
		dist[st][end] = min(dist[st][end], w);
	}

	// Floyd-warshall

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dist[i][k] == INF) continue;
			for (int j = 1; j <= n; j++) {
				if (dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] >= INF / 2) cout << "0 ";
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
}