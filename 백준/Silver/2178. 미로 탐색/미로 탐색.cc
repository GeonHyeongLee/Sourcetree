#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n;
int m;

int graph[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		auto cur = q.front(); 
		q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (visited[nx][ny] == 1) {
				continue;
			}

			if (graph[nx][ny] == 0) {
				continue;
			}

			graph[nx][ny] = graph[cur_x][cur_y] + 1;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			

		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << visited[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	return graph[n-1][m-1];
}

int main(void) {
	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = (s[j] - '0');
		}
	}

	cout << bfs(0, 0);
}