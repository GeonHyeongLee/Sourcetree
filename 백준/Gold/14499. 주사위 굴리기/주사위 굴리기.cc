#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 21
int n;
int m;
int real_x, real_y;
int k;

using namespace std;

// 동쪽 : 0, 서쪽 : 1, 북 : 2, 남 : 3
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

// 지도
int map[MAX][MAX];

// 주사위
int dice[6] = { 0,0,0,0,0,0 };

// 주사위가 이동했을 때 index = 5가 맨 마지막 바닥인데 주사위 바닥이 지도에 닿았을 때 지도 == 0
// => 주사위 바닥면 숫자가 지도 칸에 복사됨

// 지도 != 0
// => 칸에 쓰인 숫자가 주사위 바닥면 index = 5에 복사됨 + 칸에 쓰인 숫자는 0이 됨

void move_dice(int dir) {

	int copy_dice[6];

	for (int i = 0; i < 6; i++) {
		copy_dice[i] = dice[i];
	}

	// 동
	if (dir == 0) {
		real_y += 1;
		copy_dice[0] = dice[3];
		copy_dice[2] = dice[0];
		copy_dice[3] = dice[5];
		copy_dice[5] = dice[2];
	}
	// 서
	else if (dir == 1) {
		real_y -= 1;
		copy_dice[0] = dice[2];
		copy_dice[2] = dice[5];
		copy_dice[3] = dice[0];
		copy_dice[5] = dice[3];
	}
	// 북
	else if (dir == 2) {
		real_x -= 1;
		copy_dice[0] = dice[4];
		copy_dice[1] = dice[0];
		copy_dice[4] = dice[5];
		copy_dice[5] = dice[1];
	}
	// 남
	else if (dir == 3) {
		real_x += 1;
		copy_dice[0] = dice[1];
		copy_dice[1] = dice[5];
		copy_dice[4] = dice[0];
		copy_dice[5] = dice[4];
	}
	for (int i = 0; i < 6; i++) {
		dice[i] = copy_dice[i];
	}

}

void move_dice_to_map(int x, int y) {
	if (map[x][y] == 0) {
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}

	cout << dice[0] << "\n";
}

int main(void) {
		cin >> n >> m >> real_x >> real_y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;
		dir -= 1;

		int nx = real_x + dx[dir];
		int ny = real_y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}

		move_dice(dir);
		move_dice_to_map(real_x, real_y);
	}
}