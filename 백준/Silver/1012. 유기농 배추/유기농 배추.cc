#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t;
int m, n, k;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int graph[51][51];
bool visited[51][51];

void visited_init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = false;
		}
	}
}
void graph_init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			graph[i][j] = 0;
		}
	}
}

void bfs(int num_x, int num_y) {
	queue<pair<int, int>> q;
	q.push({ num_x, num_y });
	visited[num_x][num_y] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (visited[nx][ny] || graph[nx][ny] == 0) {
				continue;
			}

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main(void) {
	cin >> t;
	
	for (int c = 0; c < t; c++) {
		cin >> m >> n >> k;

		visited_init();
		graph_init();
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			graph[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == false && graph[i][j] == 1) {
					bfs(i, j);
					cnt += 1;
				}
			}
		}

		cout << cnt << "\n";
	}

}