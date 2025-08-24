#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX 31

using namespace std;

int l, r, c; // l : 높이, r : 행, c : 열
vector<vector<vector<int>>> graph(31, vector<vector<int>>(31, vector<int>(31, 0)));
vector<vector<vector<int>>> visited_minute(31, vector<vector<int>>(31, vector<int>(31, -1)));

void graph_init() {
	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				graph[k][i][j] = 0;
			}
		}
	}
}

void visited_minute_init() {
	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				visited_minute[k][i][j] = -1;
			}
		}
	}
}

int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };

void bfs(int z, int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push({ z,x,y });
	visited_minute[z][x][y] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cur_z = get<0>(cur);
		int cur_x = get<1>(cur);
		int cur_y = get<2>(cur);

		for (int i = 0; i < 6; i++) {
			int nz = cur_z + dz[i];
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) {
				continue;
			}

			if (graph[nz][nx][ny] == -3) {
				continue;
			}

			if (visited_minute[nz][nx][ny] != -1) {
				continue;
			}

			visited_minute[nz][nx][ny] = visited_minute[cur_z][cur_x][cur_y] + 1;
			q.push({ nz,nx,ny });
		}
	}

}
int main(void) {
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) {
			break;
		}
		
		graph_init();
		visited_minute_init();

		// graph의 -1: 시작점, -2 : 도착점, -3 : 통과 불가능한 점
		int st_k = 0;
		int st_i = 0;
		int st_j = 0;
		int end_k = 0;
		int end_i = 0;
		int end_j = 0;

		for (int k = 0; k < l; k++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					char s;
					cin >> s;
					if (s == 'S') {
						graph[k][i][j] = 0;
						st_k = k;
						st_i = i;
						st_j = j;
					}
					else if (s == 'E') {
						graph[k][i][j] = 0;
						end_k = k;
						end_i = i;
						end_j = j;
					}
					else if (s == '.') {
						graph[k][i][j] = 0;
					}
					else if (s == '#') {
						graph[k][i][j] = -3; 
					}
				}
			}
		}

		bfs(st_k, st_i, st_j);
		
		if (visited_minute[end_k][end_i][end_j] == -1) {
			cout << "Trapped!" << "\n";
		}
		else {
			cout << "Escaped in " << visited_minute[end_k][end_i][end_j] << " minute(s)." << "\n";
		}		
	}
}