#include <iostream>

using namespace std;

int A[1001][1001];
int s_A[1001][1001];
int B[1001][1001];

int main(void) {
	int h;
	int w;
	int x;
	int y;

	// 2 , 4 , 1 , 1
	cin >> h >> w >> x >> y;
	
	// i = 0 ~ 3, j = 0 ~ 4
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			int num;
			cin >> num;
			B[i][j] = num;
		}

	}
	// 중복 시작점
	int st_x = x;
	int st_y = y;
	// 중복 끝나는 점
	int end_x = h; 
	int end_y = w; 

	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			if (i >= st_x && i <= end_x && j >= st_y && j <= end_y) {
				B[i][j] -= B[i - x][j - y];
			}
		}
	}
	for (int i = 0; i < h ; i++) {
		for (int j = 0; j < w ; j++) {
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}
}