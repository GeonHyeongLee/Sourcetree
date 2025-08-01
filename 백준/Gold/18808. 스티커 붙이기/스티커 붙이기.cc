#include <iostream>
#include <vector>

using namespace std;

#define MAX 41

int N, M, K;
int R, C;
int sticker[MAX][MAX];
int graph[MAX][MAX];

bool Can_put_sticker(int x, int y) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sticker[i][j] == 1 && graph[x + i][y + j] == 1) {
				return false;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sticker[i][j] == 1) {
				graph[x + i][y + j] = 1;
			}
		}
	}
	return true;
}

void rotate(void) {
	int tmp[MAX][MAX];

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tmp[i][j] = sticker[i][j];
		}
	}

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			sticker[i][j] = tmp[R - 1 - j][i];
		}
	}
	swap(R, C);
}


int main(void) {
	cin >> N >> M >> K;

	while (K--) {
		cin >> R >> C;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> sticker[i][j];
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			bool already_put = false;
			for (int i = 0; i <= N - R; i++) {
				if (already_put) break;
				for (int j = 0; j <= M - C; j++) {
					if (Can_put_sticker(i, j)) {
						already_put = true;
						break;
					}
				}
			}
			if (already_put) break;
			rotate();
		}

	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1) {
				cnt += 1;
			}
		}
	}

	cout << cnt;
}