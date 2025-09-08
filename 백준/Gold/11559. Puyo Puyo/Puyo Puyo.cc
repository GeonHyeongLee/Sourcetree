// 터질 수 있는 뿌요가 여러 그룹이 있다면 
// 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<char>> field(12, vector<char>(6,0));

// 아래 : 3, 위 : 2 , 우 : 1, 좌 : 0
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


vector<vector<bool>> visited(12, vector<bool>(6, false));

int same_block_cnt = 1;
int chain_cnt = 0;


vector<pair<int, int>> store_puyo;


void push_down() {

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



void visited_init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int x, int y) {
	// 터뜨렸으니까 block 세는 건 다시 1로 초기화
	same_block_cnt = 1;
	// store_puyo도 초기화
	//while (true) {
	//	if (store_puyo.size() == 0) {
	//		break;
	//	}
	//	store_puyo.pop_back();
	//}
	// store_puyo 간단하게 초기화 store_puyo.clear();
	store_puyo.clear();

	char start_color = field[x][y];

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	store_puyo.push_back({ x,y });

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
			if (!visited[nx][ny] && field[nx][ny] == start_color) {
				visited[nx][ny] = true;
				store_puyo.push_back({ nx,ny });
				q.push({ nx,ny });
				same_block_cnt += 1;
			}
		}
	}
}

bool check_bomb() {
	// 라운드 시작 전 방문 초기화
	visited_init();

	// 한 번에 터지는 것들 저장해둘 것
	vector<pair<int, int>> erase_list;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && field[i][j] != '.') {
				bfs(i, j);
				if (same_block_cnt >= 4) {
					// .insert(위치, 넣을 리스트 처음, 끝)
					erase_list.insert(erase_list.end(), store_puyo.begin(), store_puyo.end());
				}
			}			
		}
	}

	if (erase_list.empty()) {
		return false;
	}

	for (auto& p : erase_list) {
		field[p.first][p.second] = '.';
	}
	return true;
}


void puyo_puyo() {

	while (true) {
		// 먼저 터뜨릴 수 있는지부터 확인한다
		if (check_bomb()) {
			chain_cnt++;
			push_down();
		}
		else {
			cout << chain_cnt;
			break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char c;
			cin >> c;
			field[i][j] = c;
		}
	}
	puyo_puyo();

}

// 1. 뿌요들을 중력에 따라 모두 내려준다.
// 2. 같은 색깔 4개가 인접해있는지 판단한다.
// 3. 같은 색깔 4개가 인접해있다면 그 자리를 모두 '.'으로 바꿔주고
// 연쇄 cnt에 +1을 해준다.
// 4. 다시 (1 ~ 3) 번 과정을 반복해준다.
// 만약 같은 색깔 4개가 인접해있는 곳이 없다면 종료하고 cnt를 출력한다

