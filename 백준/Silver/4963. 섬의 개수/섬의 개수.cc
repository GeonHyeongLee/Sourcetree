#include <iostream>
#include <queue>

using namespace std;

#define MAX 51

int map[MAX][MAX];
bool visited[MAX][MAX];

void map_init(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
		}
	}
}

void visited_init(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
}

// 대각선 방향까지 포함해서 방문 가능한 것으로 판단해야 한다. 그렇기에
// {-1,-1} , {-1,1} , {1, -1} , {1, 1}을 추가적으로 방문하도록 하였다
int dx[8] = {0,0,-1,1,-1,-1,1,1};
int dy[8] = {-1,1,0,0,-1,1,-1,1};

void bfs(int x, int y, int h, int w) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;

		for (int i = 0; i < 8; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				continue;
			}

			if (visited[nx][ny] || map[nx][ny] == 0) {
				continue;
			}
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main(void) {
	while (true) {
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		map_init();
		visited_init();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int num;
				cin >> num;
				map[i][j] = num;
				//cout << map[i][j] << " ";
			}
			//cout << "\n";
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					bfs(i, j, h, w);
					cnt += 1;
				}
			}
		}


		cout << cnt << "\n";
	}
}