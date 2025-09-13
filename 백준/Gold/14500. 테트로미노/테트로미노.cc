#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 505
// 정사각형 서로 겹치면 안된다
// 도형은 모두 연결되어 있어야 한다
// 정사각형의 변끼리 연결되어어 있어야 한다, 꼭짓점-꼭짓점만 맞닿으면 안된다
// 회전이나 대칭이 가능하다

// 채워넣는 형식이 아니라, 다섯가지 도형 중 하나를 넣어서 최댓값이 숫자를 구해라
int n;
int m;
int graph[MAX][MAX];
vector<pair<int, int>> tet;

int max_num = 0;

vector<pair<int, int>> all_tet[19] =
{
{{0,0},{0,1},{0,2},{0,3}},
{{0,0},{1,0},{2,0},{3,0}},
{{0,0},{0,1},{1,0},{1,1}},
{{0,0},{1,0},{2,0},{2,1}},
{{0,0},{1,0},{0,1},{0,2}},
{{0,0},{0,1},{1,1},{2,1}},
{{1,0},{1,1},{1,2},{0,2}},
{{2,0},{0,1},{1,1},{2,1}},
{{0,0},{1,0},{1,1},{1,2}},
{{0,0},{1,0},{2,0},{0,1}},
{{0,0},{0,1},{0,2},{1,2}},
{{0,0},{1,0},{1,1},{2,1}},
{{0,1},{0,2},{1,0},{1,1}},
{{1,0},{1,1},{0,1},{2,0}},
{{0,0},{0,1},{1,1},{1,2}},
{{0,0},{0,1},{0,2},{1,1}},
{{1,0},{0,1},{1,1},{2,1}},
{{1,0},{0,1},{1,1},{1,2}},
{{0,0},{1,0},{2,0},{1,1}},
};

void calculate_max(vector<pair<int, int>>& tet) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		result += graph[tet[i].first][tet[i].second];
	}
	max_num = max(max_num, result);
}

void find_biggest(int x, int y) {
	
	vector<pair<int, int>> tet;

	for (int i = 0; i < 19; i++) {
		tet.clear();
		for (int j = 0; j < 4; j++) {
			tet.push_back({ x + all_tet[i][j].first, y + all_tet[i][j].second });
		}
		calculate_max(tet);
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			find_biggest(i, j);
		}
	}

	cout << max_num;
}