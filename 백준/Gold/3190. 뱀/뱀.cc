#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>


#define MAX 101
using namespace std;

int n, k, l;
int result;
int cur_dir = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int graph[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int row, col;
		cin >> row >> col;
		graph[row-1][col-1] = 1;
	}

	cin >> l;
	queue<pair<int, char>> q;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		q.push({ x,c });
	}

	graph[0][0] = 2;
	deque<pair<int, int>> dq;
	dq.push_back({ 0,0 });

	while (true) {
		result++;
		auto cur = dq.back();
		int cur_x = cur.first;
		int cur_y = cur.second;
		int nx = cur_x + dx[cur_dir];
		int ny = cur_y + dy[cur_dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			break;
		}

		if (graph[nx][ny] == 2) {
			break;
		}

		if (graph[nx][ny] != 1) {
			graph[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}

		graph[nx][ny] = 2;
		dq.push_back({ nx,ny });

		if (result == q.front().first) {
			char change_dir = q.front().second;
			if (change_dir == 'D') {
				cur_dir += 1;
				if (cur_dir == 4) {
					cur_dir = 0;
				}
			}
			else {
				cur_dir -= 1;
				if (cur_dir == -1) {
					cur_dir = 3;
				}
			}
			q.pop();
		}

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << graph[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}

	cout << result;

}
