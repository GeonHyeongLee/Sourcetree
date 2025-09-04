#include <iostream>
#include <vector>
#include <queue>
#include <string>


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
	queue<pair<pair<int, int>,pair<int, int>>> q;
	q.push({ { 0,0 }, { 0,1 } });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cur_x = cur.first.first;
		int cur_y = cur.first.second;

		int pass_wall_cnt = cur.second.first;
		int result = cur.second.second;

		if (cur_x == n - 1 && cur_y == m - 1) {
			return result;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (graph[nx][ny] == 1 && pass_wall_cnt == 0 && visited[nx][ny][1] == 0) {
				visited[nx][ny][pass_wall_cnt + 1] = 1;
				q.push({ {nx,ny}, {pass_wall_cnt + 1, result + 1} });
			}
			else if (graph[nx][ny] == 0 && visited[nx][ny][pass_wall_cnt] == false) {
				visited[nx][ny][pass_wall_cnt] = 1;
				q.push({ {nx,ny}, {pass_wall_cnt , result + 1} });
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