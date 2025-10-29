#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 26
using namespace std;

int n;
int cnt = 0;

bool visited[MAX][MAX];
int graph[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs(int x, int y, int& num) {
	queue<pair<int,int>> q;
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			if (visited[nx][ny] || graph[nx][ny] == 0) {
				continue;
			}

			q.push({ nx,ny });
			visited[nx][ny] = true;
			num++;
		}
	}

}

int main(void) {
	cin >> n;
	cin.ignore();


	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < n; j++) {
			int num = s[j] - '0';
			graph[i][j] = num;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	vector<int> apart_count;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && graph[i][j] == 1) {
				int apart_num = 1;
				bfs(i, j, apart_num);
				cnt++;
				apart_count.push_back(apart_num);
			}
		}
	}
	sort(apart_count.begin(), apart_count.end());

	cout << cnt << "\n";

	for (int i = 0; i < apart_count.size(); i++) {
		cout << apart_count[i] << "\n";
	}
}