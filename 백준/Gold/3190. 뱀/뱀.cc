#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 101

int graph[MAX][MAX];

int n, k, l;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int cur_dir = 0;
int time_result = 0;

int main(void) {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int row, col;
		cin >> row >> col;
		graph[row - 1][col - 1] = 1;
	}

	cin >> l;
	
	queue<pair<int, char>> transfer;

	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		transfer.push({ x,c });
	}
	graph[0][0] = 2;
	deque<pair<int, int>> snake;
	snake.push_back({ 0,0 });

	while (true) {
		time_result++;
		
		auto cur = snake.back();
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
			auto head = snake.front();
			int head_x = head.first;
			int head_y = head.second;
			graph[head_x][head_y] = 0;
			snake.pop_front();
		}

		graph[nx][ny] = 2;
		snake.push_back({ nx,ny });

		
		if (!transfer.empty() && time_result == transfer.front().first) {
			char c = transfer.front().second;
			if (c == 'D') cur_dir = (cur_dir + 1) % 4;
			else          cur_dir = (cur_dir + 3) % 4;
			transfer.pop();
		}

	}
	
	cout << time_result;
}