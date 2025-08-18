#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> gears[4];

void move_gear(int num, int dir) {
	vector<int> gear_copy;

	for (int i = 0; i < gears[num].size(); i++) {
		gear_copy.push_back(gears[num][i]);
	}

	// 시계 반시계 헷갈리지 않도록 하자 헷갈리면 {0,1,2,3,4,5,6,7} 기준으로 해볼 것
	if (dir == 1) {
		gears[num][0] = gear_copy[7];
		for (int i = 1; i <= 7; i++) {
			gears[num][i] = gear_copy[i - 1];
		}
	}
	else if (dir == -1) {
		gears[num][7] = gear_copy[0];
		for (int i = 0; i < 7; i++) {
			gears[num][i] = gear_copy[i + 1];
		}
	}
	// 안 돌릴 때에는 dir == 0이므로 그냥 그대로 종료
	else {
		return;
	}
}



void calculate_result(int& result) {
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
}

int main(void) {
	string gear;
	for (int i = 0; i < 4; i++) {
		cin >> gear;
		for (int j = 0; j < 8; j++) {
			gears[i].push_back((gear[j] - '0'));
		}
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int num, dir;
		cin >> num >> dir;
		num = num - 1;

		int dirs[4] = { 0,0,0,0 }; // 방향을 먼저 정해놓고 한 번에 돌리기 위해서 준비한다
		dirs[num] = dir;

		// gear 넘버 기준으로 왼쪽 기어가 어떻게 변할 지 판단
		for (int i = num - 1; i >= 0; i--) {
			if (gears[i][2] != gears[i+1][6]) {
				dirs[i] = -dirs[i + 1];
			}
			else {
				break;
			}
		}
		// gear 넘버 기준으로 오른쪽 기어가 어떻게 변할 지 판단
		for (int i = num + 1; i < 4; i++) {
			if (gears[i - 1][2] != gears[i][6]) {
				dirs[i] = -dirs[i - 1];
			}
			else {
				break;
			}
		}

		// 최종적으로 정해진 방향에 따라 모든 기어 회전
		for (int i = 0; i < 4; i++) {
			move_gear(i, dirs[i]);
		}
	}

	// 회전된 기어의 값
	int result = 0;
	calculate_result(result);

	cout << result;
}