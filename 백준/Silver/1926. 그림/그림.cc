#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 501

int n, m;
int graph[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = { 0, 0, -1,1 };
int dy[4] = { -1,1,0,0 };

vector<int> result;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int cnt = 1;

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
			else if (visited[nx][ny] || graph[nx][ny] == 0) {
				continue;
			}
			else if (visited[nx][ny] == false && graph[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt += 1;
			}
		}
	}
	result.push_back(cnt);
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

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

	int max_num = 0;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] > max_num) {
			max_num = result[i];
		}
	}
	cout << max_num << "\n";
}