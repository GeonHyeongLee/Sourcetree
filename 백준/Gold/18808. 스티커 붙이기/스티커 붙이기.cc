#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int n, m, k;

int r, c;

int sticker[41][41];
int map[41][41];

// sticker[41][41]에 하나 입력할 때마다 map 벡터에 저장할 수 있는지 확인하고
// 저장할 수 있으면 map파일을 업데이트 해나가는 방식으로 진행하면 될 거 같다.


int calc_sum() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				cnt += 1;
			}
		}
	}
	return cnt;
}

// sticker는 매번 받을 때마다 초기화를 해줘야 하므로 k가 넘어갈때마다 초기화해주자
void sticker_init(void) {
	for (int i = 0; i < 41; i++) {
		for (int j = 0; j < 41; j++) {
			sticker[i][j] = 0;
		}
	}
}


// 90도로 한번씩 돌릴때마다 체크를 해줘야 하는데 
// 행렬에서 90도로 돌리면 n*m행렬 기준 (x,y) => (y, n-x-1)이 된다.
void rotate(void) {
	int tmp[41][41];
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			tmp[i][j] = sticker[r - j - 1][i];
		}
	}

	sticker_init();

	for (int i = 0; i < 41; i++) {
		for (int j = 0; j < 41; j++) {
			sticker[i][j] = tmp[i][j];
		}
	}
	swap(r, c);
}

// 들어갈 수 있는지 여부를 확인해야 할 것이다.
bool can_put(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int nxtR = i + y;
			int nxtC = j + x;

			if ((sticker[i][j] == 1) && (map[nxtR][nxtC] == 1)) {
				return false;
			}
		}
	}
	return true;
}

void sticking(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int nxtR = i + y;
			int nxtC = j + x;
			if (sticker[i][j] == 1) {
				map[nxtR][nxtC] = sticker[i][j];
			}
		}
	}
}

bool sticker_attach(void) {
	for (int i = 0; i < (n - r + 1); i++) {
		for (int j = 0; j < (m - c + 1); j++) {
			if (can_put(i, j)) {
				sticking(i, j);
				return true;
			}
		}
	}
	return false;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int idx = 0; idx < k; idx++) {

		sticker_init();
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}

		bool isAttach = sticker_attach();
		if (isAttach) {
			continue;
		}

		for (int k = 0; k < 3; k++) {
			rotate();
			isAttach = sticker_attach();
			if (isAttach) {
				break;
			}
		}


	}

	cout << calc_sum() << "\n";



}