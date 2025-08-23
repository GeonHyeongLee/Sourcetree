#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1001

int m; // 열
int n; // 행

int graph[MAX][MAX];
int visited_day[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main(void) {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited_day[i][j] = -1;
			if (graph[i][j] == 1) {
				visited_day[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	// 한 번에 q에 여러 개를 넣고 실행해도 될까?
	// 가능하다! 처음 큐에 (0,0), (2,3), (4,5)가 들어가있으면
	// 이 세곳에서 동시에 하루만에 옆칸을 익히게 된다.
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (visited_day[nx][ny] != -1) {
				continue;
			}

			if (graph[nx][ny] == -1) {
				continue;
			}

			if (graph[nx][ny] == 0) {
				visited_day[nx][ny] = visited_day[cur_x][cur_y] + 1;
				q.push({ nx,ny });
				graph[nx][ny] = 1;
			}

		}

	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}

			result = max(visited_day[i][j], result);
		}
	}

	cout << result << "\n";
}