#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

#define MAX 1001

using namespace std;


int n;
int m;
string s;

int graph[MAX][MAX];
int visited[MAX][MAX][2];
int dist[MAX][MAX][2];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


int bfs() {
	// q에 {x,y}, 벽 부순 횟수 저장, 안에 요소가 3개이기 때문에 tuple 사용

	queue<tuple<int, int, int>> q;
	q.push({0,0, 0 });
	// dist로 따로 둬서 사용할거라면 visited는 필요 없음.
	dist[0][0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cur_x = get<0>(cur);
		int cur_y = get<1>(cur);
		int wall_pass = get<2>(cur);

		if (cur_x == n - 1 && cur_y == m - 1) {
			return dist[cur_x][cur_y][wall_pass];
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (graph[nx][ny] == 0) {
				if (dist[nx][ny][wall_pass] == 0) {
					dist[nx][ny][wall_pass] = dist[cur_x][cur_y][wall_pass] + 1;
					q.push({ nx,ny, wall_pass });
				}
			}
			else {
				if (dist[nx][ny][1] == 0 && wall_pass == 0) {
					dist[nx][ny][wall_pass + 1] = dist[cur_x][cur_y][wall_pass] + 1;
					q.push({ nx,ny,1 });
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = (s[j] - '0');
		}
	}

	cout << bfs();

}