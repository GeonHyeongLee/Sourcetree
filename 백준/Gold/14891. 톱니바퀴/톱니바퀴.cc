#include <iostream>
#include <vector>

using namespace std;

#define MAX 8

int gears[MAX][MAX];

void move_gear(int gear_num, int dir) {

	int gear_copy[MAX];

	for (int i = 0; i < 8; i++) {
		gear_copy[i] = gears[gear_num][i];
	}

	if (dir == 1) {
		// {0,1,2,3,4,5,6,7} => {7,0,1,2,3,4,5,6}
		gears[gear_num][0] = gear_copy[7];
		for (int i = 1; i <= 7; i++) {
			gears[gear_num][i] = gear_copy[i - 1];
		}
	}
	else if (dir == -1) {
		// {0,1,2,3,4,5,6,7} => {1,2,3,4,5,6,7,0}
		gears[gear_num][7] = gear_copy[0];
		for (int i = 0; i < 7; i++) {
			gears[gear_num][i] = gear_copy[i + 1];
		}
	}
	else {
		return;
	}
}

int main(void) {
	string gear;
	for (int i = 0; i < 4; i++) {
		cin >> gear;
		for (int j = 0; j < 8; j++) {
			gears[i][j] = (gear[j] - '0');
		}
	}

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		cout << gears[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int gear_num, dir;
		cin >> gear_num >> dir;

		gear_num -= 1;
		int dirs[4] = { 0,0,0,0 };
		dirs[gear_num] = dir;

		// 기어 기준 오른쪽
		for (int i = gear_num + 1; i < 4; i++) {
			if (gears[i-1][2] != gears[i][6]) {
				dirs[i] = -dirs[i-1];
			}
		}
		// 기어 기준 왼쪽
		for (int i = gear_num - 1; i >= 0; i--) {
			if (gears[i+1][6] != gears[i][2]) {
				dirs[i] = -dirs[i+1];
			}
		}

		for (int i = 0; i < 4; i++) {
			move_gear(i, dirs[i]);
		}
	}

	int	result = 0;

	if (gears[0][0] == 1) {
		result += 1;
	}
	if (gears[1][0] == 1) {
		result += 2;
	}
	if (gears[2][0] == 1) {
		result += 4;
	}
	if (gears[3][0] == 1) {
		result += 8;
	}

	cout << result << "\n";
}