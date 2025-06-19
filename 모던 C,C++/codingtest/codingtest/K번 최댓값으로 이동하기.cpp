#include <iostream>
#include <tuple>
#include <queue>

#define MAX 100
#define NOT_EXISTS make_pair(-1,-1)


// 전체적인 구조는 bool Move안에
// void BFS
// void initilaizeVisited
// bool NeedUpdate
// 이 셋이 들어가 있는 구조이고

// void BFS안에는
// Cango가 들어가서 BFS 알고리즘을 진행한다.


// MOVE가 false => 진행 루트가 없을 때 or while문을 통해 K == 0일 때 종료
// MOVE 안에서는 매번 방문 배열을 초기화하고 BFS 진행
// 
using namespace std;

int n, k;

int grid[MAX][MAX];
int visited[MAX][MAX];

pair<int, int> curr_cell;

queue<pair<int, int>> bfs_q;

bool visited[MAX][MAX];

bool Cango(int x, int y, int target_num) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return false;
	}
	else if (grid[x][y] >= target_num || visited[x][y]) {
		return false;
	}
	return true;
}

void initializeVistied() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

void BFS() {
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	int start_x;
	int start_y;

	tie(start_x, start_y) = curr_cell; // start_x = (4-1), start_y = (3-1) => (3,2)
	visited[start_x][start_y] = true;

	bfs_q.push(curr_cell);

	int target_num = grid[start_x][start_y];

	while (!bfs_q.empty()) {
		pair<int, int> curr_pos = bfs_q.front();
		int curr_x, curr_y;
		tie(curr_x, curr_y) = curr_pos;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if (Cango(nx, ny, target_num)) {
				bfs_q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
}

bool needupdate(pair<int, int> best_pos, pair<int, int> new_pos) {
	if (best_pos == NOT_EXISTS)
		return true;

	int best_x, best_y; // 비교 당하는 대상
	tie(best_x, best_y) = best_pos;

	int new_x, new_y; // 비교 위한 숫자
	tie(new_x, new_y) = new_pos;

	// 숫자 , 행 , 열 순으로 비교
	return make_tuple(grid[new_x][new_y], -new_x, -new_y) > make_tuple(grid[best_x][best_y], -best_x, -best_y);

}


bool Move() {
	initializeVistied();
	BFS();

	pair<int, int> best_pos = NOT_EXISTS;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 방문하지 못하는 지역이거나 현재 위치와 동일하다면 패스
			if (!visited[i][j] || make_pair(i, j) == curr_cell)
				continue;

			pair<int, int> new_pos = make_pair(i, j);
			if (needupdate(best_pos, new_pos))
				best_pos = new_pos;
		}
	}

	if (best_pos == NOT_EXISTS)
		return false;
	else {
		curr_cell = best_pos;
		return true;
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	int r, c;
	cin >> r >> c;
	curr_cell = make_pair(r - 1, c - 1);

	while (k--) {
		bool is_moved = Move();

		// 못 움직이면 바로 종료
		if (!is_moved)
			break;
	}

	int final_x, final_y;
	tie(final_x, final_y) = curr_cell;
	cout << final_x + 1 << " " << final_y + 1;
}