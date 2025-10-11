#include <iostream>
#include <vector>
#include <queue>

#define MAX 51

using namespace std;

int T;

int M, N, K;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int result = 0;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void graph_init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			graph[i][j] = 0;
		}
	}
}
void visited_init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;
		
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx >= M || nx < 0 || ny >= N || ny < 0) {
				continue;
			}

			if (visited[nx][ny] || graph[nx][ny] == 0) {
				continue;
			}

			visited[nx][ny] = true;
			//cout << nx << "," << ny << "get true\n";
			q.push({ nx,ny });

		}
	}
}

int main(void) {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		
		graph_init();
		visited_init();
		result = 0;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}

		//for (int j = 0; j < M; j++) {
		//	for (int q = 0; q < N; q++) {
		//		cout << graph[j][q] << " ";
		//	}
		//	cout << "\n";
		//}

		for (int p = 0; p < M; p++) {
			for (int q = 0; q < N; q++) {
				if (!visited[p][q] && graph[p][q] == 1) {
					//cout << "hello" << "\n";
					bfs(p, q);
					result += 1;
				}
			}
		}

		cout << result << "\n";
	}
}