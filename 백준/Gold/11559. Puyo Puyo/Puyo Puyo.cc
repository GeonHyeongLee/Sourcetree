#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<char>> field(12, vector<char>(6, 0));

int same_block_cnt = 1;
int chain_bomb = 0;

vector<vector<bool>> visited(12, vector<bool>(6, false));

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<pair<int, int>> store_same_colors;

void visited_init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = false;
		}
	}
}


// 얘는 잘 되어있음
void pull_down() {

	vector<vector<char>> copy_field(12, vector<char>(6, '.'));

	for (int j = 0; j < 6; j++) {
		vector<char> v;
		for (int i = 0; i < 12; i++) {
			if (field[i][j] != '.') {
				v.push_back(field[i][j]);
			}
		}
		int cnt = 0;
		for (int i = (12 - v.size()); i < 12; i++) {
			copy_field[i][j] = v[cnt];
			cnt++;
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			field[i][j] = copy_field[i][j];
		}
	}
}

void bfs(int x, int y) {

	same_block_cnt = 1;

	store_same_colors.clear();
	store_same_colors.push_back({ x,y });

	char st_color = field[x][y];	

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	
	while (!q.empty()) {

		auto cur = q.front(); q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) {
				continue;
			}
			if (!visited[nx][ny] && field[nx][ny] == st_color) {
				same_block_cnt += 1;
				store_same_colors.push_back({ nx,ny });
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

bool can_bomb() {
	
	visited_init();
	
	vector<pair<int, int>> bombs;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && field[i][j] != '.') {
				bfs(i, j);
				if (same_block_cnt >= 4) {
					bombs.insert(bombs.end(), store_same_colors.begin(), store_same_colors.end());
				}
			}
		}
	}

	if (bombs.empty()) {
		return false;
	}

	for (int i = 0; i < bombs.size(); i++) {
		auto bomb = bombs[i];
		int bomb_x = bomb.first;
		int bomb_y = bomb.second;
		field[bomb_x][bomb_y] = '.';
	}

	return true;
}

void puyo_puyo() {
	while (true) {
		if (can_bomb()) {
			pull_down();
			chain_bomb += 1;
		}
		else {
			cout << chain_bomb << "\n";
			break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}

	puyo_puyo();

}