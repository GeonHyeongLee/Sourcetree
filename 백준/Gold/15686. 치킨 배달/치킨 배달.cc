#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;


#define MAX 51

int n, m;
int graph[MAX][MAX];


vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;

int best = 987654321;

vector<int> result;

int city_chicken_dis(vector<int>& result) {
	// result가 {0 , 1}이라고 한다면 방문할 치킨집은
	// chickens[0]과 chickens[1]

	// 집을 기준으로 찾아야하므로 집 먼저

	int real_result = 0;

	for (auto house : houses) {
		int house_x = house.first;
		int house_y = house.second;

		int min_dist = 987654321;

		for (int i = 0; i < result.size(); i++) {
			int chicken_num = result[i];
			int chicken_x = chickens[chicken_num].first;
			int chicken_y = chickens[chicken_num].second;

			int dist = abs(house_x - chicken_x) + abs(house_y - chicken_y);

			min_dist = min(min_dist, dist);
		}
		real_result += min_dist;

		// "추가" 이미 real_result가 best를 넘어섰다면 볼 필요 없을 것
		if (real_result >= best) {
			return real_result;
		}
	}

	return real_result;
}

void find_permutation(int cur, int cnt) {
	if (cnt == m) {
		// "중요" 
		// 조합을 진행하면서 뽑은 result를 그대로 거리를 구해서 최솟값을 
		// 구해나갔다면 처음 했던 것처럼 vector<vector<int>>를 만들어서
		// 다시 저장할 필요가 없었을 것이다.
		best = min(best, city_chicken_dis(result));
		return;
	}

	// "추가" 
	// chicken 개수에서 cur 즉 현재 보고 있는 치킨 번호만큼 뺐을 때
	// m - cnt보다 작다, 즉 남은 치킨 번호 수가 채워야 될 치킨 번호 수보다
	// 적다면 종료
	if (chickens.size() - cur < m - cnt) {
		return;
	}

	for (int i = cur; i < chickens.size(); i++) {
		result.push_back(i);
		// 중요 : 조합은 현재 고른 인덱스 i의 다음부터만 고른다
		// i + 1일 때는 (1,2), (1,3), (1,4) ...
		// cur + 1일 때는 (1,1),(1,2),(1,3),(1,4),(2,1),(2,2) 
		// 이런식으로 (2,1)과 같이 볼 필요 없는 것들도 보게되므로 시간 초과
		find_permutation(i + 1, cnt + 1); 

		result.pop_back();
	}
}


int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				houses.push_back({ i,j });
			}
			else if (graph[i][j] == 2) {
				chickens.push_back({ i,j });
			}
		}
	}

	// 치킨 조합 만들기
	find_permutation(0,0);

	cout << best;

}
