#include <iostream>
#include <vector>

#define MAX 51

using namespace std;
int n;
int m;

int board[MAX][MAX];
int visited[MAX][MAX];

char black_chess[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

char white_chess[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

bool can_make_chess(int x, int y) {

	if (x + 8 > n || y + 8 > m) {
		return false;
	}

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (visited[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char color;
			cin >> color;
			board[i][j] = color;
		}
	}

	// 체스판은 옆으로 움직일 때마다 색깔이 달라져야 한다
	// 맨 위에서부터 시작해서 흰색 기준, 검은색 기준으로 했을 때
	// 몇 개를 바꿔야 하는지를 세서 적은 기준으로 더해준다

	int result = 12345;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (can_make_chess(i, j)) {
				int black_cnt = 0;
				int white_cnt = 0;
				char chess[8][8];

				for (int p = 0; p < 8; p++) {
					for (int q = 0; q < 8; q++) {
						chess[p][q] = board[i+p][j+q];
					}
				}

	/*			for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << chess[i][j] << " ";
					}
					cout << "\n";
				}*/

				for (int p = 0; p < 8; p++) {
					for (int q = 0;q < 8; q++) {
						if (chess[p][q] != black_chess[p][q]) {
							black_cnt += 1;
							//cout << "black_cnt : " << black_cnt << "\n";
						}
						if (chess[p][q] != white_chess[p][q]) {
							white_cnt += 1;
							//cout << "white_cnt : " << white_cnt << "\n";
						}
					}
				}

				int min_chess = min(black_cnt, white_cnt);
				result = min(min_chess, result);
			}
		}
	}

	cout << result;
}