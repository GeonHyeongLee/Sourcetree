#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 987654321
int n; // 열
int m; // 행

using namespace std;


int graph[MAX][MAX];
int table[MAX][MAX];
int min_num = 987654321;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dijkstra(void) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j] = INF;
		}
	}
	
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	pq.push({ 0, { 0,0 } });

	table[0][0] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int cur_weight = cur.first;
		int cur_x = cur.second.first;
		int cur_y = cur.second.second;

		if (table[cur_x][cur_y] < cur_weight) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}

			int next_weight = cur_weight + graph[nx][ny];

			if (next_weight < table[nx][ny]) {
				table[nx][ny] = next_weight;
				pq.push({ table[nx][ny], {nx,ny} });
			}
		}
	}
}

int main(void) {
	cin >> n >> m;

	string s;

	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			graph[i][j] = (s[j] - '0');
		}
	}

	
	dijkstra();


	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << table[i][j] << " ";
	//	}
	//	cout << "\n";
	//}


	cout << table[m-1][n-1];
}