#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int graph[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int res = 987654321;

vector<pair<int, int>> cctv;

void check(int x, int y, int dir) {

	dir %= 4;

	while (1) {
		x = x + dx[dir];
		y = y + dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M) {
			return;
		}

		if (graph[x][y] == 6) {
			return;
		}

		// 왜 그냥 다 -1로 덮어버리면 안되나?
		// 그럼 다음 cctv도 덮어버려서 실행을 못하게 할 수 있기 때문이다
		if (graph[x][y] == 0) {
			graph[x][y] = -1;
		}
	}
}

void dfs(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 0) {
					cnt += 1;
				}
			}
		}

		res = min(res, cnt);
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	int tmp[MAX][MAX];

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = graph[i][j];
			}
		}

		if (graph[x][y] == 1) {
			check(x, y, dir);
		}
		else if (graph[x][y] == 2) {
			check(x, y, dir);
			check(x, y, dir + 2);
		}
		else if (graph[x][y] == 3) {
			check(x, y, dir);
			check(x, y, dir + 1);
		}
		else if (graph[x][y] == 4) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
		}
		else if (graph[x][y] == 5) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
		}

		dfs(idx + 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] = tmp[i][j];
			}
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];

			if (graph[i][j] >= 1 && graph[i][j] <= 5) {
				cctv.push_back({ i,j });
			}
		}
	}

	dfs(0);


	cout << res << "\n";
}