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

vector<int> result;

vector<vector<int>> choosing_chickens; // 조합이 담겨있다

void find_permutation(int cur, int cnt) {
	if (cnt == m) {

		choosing_chickens.push_back(result);
		return;
	}

	for (int i = cur; i < chickens.size(); i++) {
		result.push_back(i);
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

	int min_num = 987654321;


	vector<int> real_result;


	for (int i = 0; i < choosing_chickens.size(); i++) {
		int min_chicken_dis = 0;
		for (int k = 0; k < houses.size(); k++) {

			int house_x = houses[k].first;
			int house_y = houses[k].second;

			int min_dis = 98765431;
			for (int j = 0; j < choosing_chickens[i].size(); j++) {
				int chicken_num = choosing_chickens[i][j];
				int chicken_x = chickens[chicken_num].first;
				int chicken_y = chickens[chicken_num].second;

				int dis = abs(house_x - chicken_x) + abs(house_y - chicken_y);
				min_dis = min(min_dis, dis);
			}
			min_chicken_dis += min_dis;
		}
		real_result.push_back(min_chicken_dis);
	}

	for (int i = 0; i < real_result.size(); i++) {
		if (real_result[i] < min_num) {
			min_num = real_result[i];
		}
	}

	cout << min_num;
}
