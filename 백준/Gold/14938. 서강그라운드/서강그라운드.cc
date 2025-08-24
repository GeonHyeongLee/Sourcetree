#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int n; // 정점 개수
int m; // 최대 수색치 <- INF?
int r; // 간선 개수



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	vector<int> items(n + 1, 0);
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));


	// 자신에서 자신으로 이동하는 거리는 무조건 0일 것
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	// 각 정점별로 가진 아이템 수 => 얘로 결과값 낼 거
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}

	// 간선 정보 -> 어디서 어디로 가는지 가중치는 어느 정도인지
	for (int i = 0; i < r; i++) {
		int st, end, w;
		cin >> st >> end >> w;
		dist[st][end] = min(dist[st][end], w);
		dist[end][st] = min(dist[end][st], w);
	}

	// 플로이드-와셜 알고리즘
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dist[i][k] == INF) continue;
			for (int j = 1; j <= n; j++) {
				if (dist[k][j] == INF) continue;
			
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			
			}
		}
	}

	
	int max_num = 0;

	for (int i = 1; i <= n; i++) {
		int result = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) {
				result += items[j];
			}
		}
		max_num = max(max_num, result);
	}



	cout << max_num;
}