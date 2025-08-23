#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


int m; // 행
int n; // 열
int h; // 높이

vector<vector<vector<int>>> graph(101, vector<vector<int>>(101, vector<int>(101)));
vector<vector<vector<int>>> visited_day(101, vector<vector<int>>(101, vector<int>(101, -1)));


int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };

int main(void) {
	cin >> m >> n >> h;

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1) {
					visited_day[i][j][k] = 0;
					q.push({ i,j,k });
				}
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int z = get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);

		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (visited_day[nz][nx][ny] != -1) {
				continue;
			}

			if (graph[nz][nx][ny] == -1) {
				continue;
			}

			if (graph[nz][nx][ny] == 0) {
				graph[nz][nx][ny] = 1;
				visited_day[nz][nx][ny] = visited_day[z][x][y] + 1;
				q.push({ nz,nx,ny });
			}
		}
	}

	int max_result = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (graph[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}

				max_result = max(max_result, visited_day[i][j][k]);
			}
		}
	}

	cout << max_result << "\n";
}