#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 30

int n;

int graph[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

vector<int> result;

void bfs(int x, int y, int& cnt) {

	queue<pair<int, int>> q;
	q.push({ x,y });
	cnt += 1;
	visited[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cur_x = cur.first;
		int cur_y = cur.second;
		//cout << cur_x << " " << cur_y << "\n";
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			if (visited[nx][ny] || graph[nx][ny] == 0) {
				continue;
			}

			visited[nx][ny] = true;
			cnt += 1;
			q.push({ nx, ny });
		}

	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			graph[i][j] = (s[j] - '0');
		}
	}

	int town_cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && graph[i][j] == 1) {
				town_cnt += 1;
				int cnt = 0;
				bfs(i, j, cnt);
				result.push_back(cnt);
			}
		}
	}

	cout << town_cnt << "\n";

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}