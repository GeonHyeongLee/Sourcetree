#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


#define MAX 101
int m; // 열
int n; // 행
int h; // 높이

vector<vector<vector<int>>> graph(101, vector<vector<int>>(101, vector<int>(101)));
vector<vector<vector<int>>> visited_day(101, vector<vector<int>>(101, vector<int>(101, -1)));

int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };

int main(void) {
	cin >> m >> n >> h;

	queue<tuple<int, int, int>> q;


	// 높이 => 행 => 열 순으로 입력 받기
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> graph[i][j][k]; 
				if (graph[i][j][k] == 1) {
					visited_day[i][j][k] = 0;
					q.push({ i,j,k });
				}
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		// tuple에서는 q.first, seocnd가 아닌 get<0>(cur) 이런식으로 출력
		int z = get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);

		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			
			// -1로 토마토가 들어있지 않은 점은 방문하지 않는다.
			if (graph[nz][nx][ny] == -1) {
				continue;
			}
			
			// 방문 했으면 재방문 안한다.
			if (visited_day[nz][nx][ny] != -1) {
				continue;
			}
			// 토마토가 익지 않은 점을 방문하여서
			// visited_day는 그전보다 +1, 익었으니까 graph의 해당 지점은 1로 바뀜
			// 이후 q.push하여 해당 위치를 q에 저장
			if (graph[nz][nx][ny] == 0) {
				visited_day[nz][nx][ny] = visited_day[z][x][y] + 1;
				graph[nz][nx][ny] = 1;
				q.push({ nz,nx,ny });
			}
		}

	}

	int max_result = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (graph[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}

				max_result = max(max_result, visited_day[i][j][k]);
			}
		}
	}

	cout << max_result << "\n";

	/*cout << "\n\n";

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cout << v[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}*/



}