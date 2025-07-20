#include <iostream>

using namespace std;

int n, m, k;
int r, c;

#define MAX 41
int sticker[MAX][MAX];
int graph[MAX][MAX];

int result(void) {
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (graph[i][j] == 1) {
				cnt += 1;
			}
		}
	}
	return cnt;
}

void sticker_init(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sticker[i][j] = 0;
		}
	}
}

void rotate(void) {
	int tmp[MAX][MAX];

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			tmp[i][j] = sticker[r - j - 1][i];
		}
	}

	sticker_init();

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sticker[i][j] = tmp[i][j];
		}
	}

	swap(r, c);
}


// y,x에서 스티커가 그래프에 들어갈 수 있는지 여부 판단
bool can_put(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int nxtR = y + i;
			int nxtC = x + j;

			// 만약 y,x 기준으로 sticker를 쭉 옮겨봤을 때 sticker가 1일 때
			// graph도 1이라면 붙일 수가 없을 것이다
			if (graph[nxtR][nxtC] == 1 && sticker[i][j] == 1)
				return false;
		}
	}
	return true;
}

// 이번엔 graph 전체에서 y,x를 옮겨가면서 스티커가 들어간다면 graph를 1로 바꿔줌

bool input_sticker() {
	for (int i = 0; i < n - r + 1; i++) {
		for (int j = 0; j < m - c + 1; j++) {

			if (can_put(i, j)) {
				for (int p = 0; p < r; p++) {
					for (int q = 0; q < c; q++) {
						int nxtR = p + i;
						int nxtC = q + j;

						if (sticker[p][q] == 1) {
							graph[nxtR][nxtC] = 1;
						}
					}
				}

				return true;
			}
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int idx = 0; idx < k; idx++) {
		cin >> r >> c;

		sticker_init();

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int num;
				cin >> num;
				sticker[i][j] = num;
			}
		}

		bool isattach = input_sticker();

		if (isattach == true) {
			continue;
		}

		for (int i = 0; i < 3; i++) {
			rotate();
			isattach = input_sticker();
			if (isattach == true) {
				break;
			}
		}

	}

	cout << result() << "\n";

	return 0;
}