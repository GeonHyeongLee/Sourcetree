#include <iostream>
#include <vector>
#include <queue>

#define MAX 126
#define INF 987654321

using namespace std;

int n;
int graph[MAX][MAX];
int table[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void dijkstra(void) {
	priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j] = INF;
		}
	}

	pq.push({ graph[0][0], { 0,0 } });
	table[0][0] = graph[0][0];

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cur_weight = cur.first;
		pair<int, int> cur_point = cur.second;
		int cur_x = cur_point.first;
		int cur_y = cur_point.second;


		if (cur_weight > table[cur_x][cur_y]) {
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			int nxt_weight = cur_weight + graph[nx][ny];

			if (nxt_weight < table[nx][ny]) {
				table[nx][ny] = nxt_weight;
				pq.push({ table[nx][ny], { nx,ny } });
			}
		}
	}
}

int main(void) {
	int cnt = 1;
	
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int p = 0; p < n; p++) {
			for (int q = 0; q < n; q++) {
				cin >> graph[p][q];
			}
		}

		dijkstra();

		cout << "Problem " << cnt << ": " << table[n - 1][n - 1] << "\n";
		cnt++;
	}
	return 0;
}