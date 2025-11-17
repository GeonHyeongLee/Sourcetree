#include <iostream>
#include <vector>
#include <queue>

#define MAX 801
#define INF 987654321


using namespace std;

int N, E;
int a, b, c;

// 임의로 주어진 두 정점은 반드시 통과해야 한다
int v1, v2;

vector<pair<int, int>> graph[MAX];

int calculate_min_range(int st, int ed) {

	int table[MAX];

	for (int i = 0; i < MAX; i++) {
		table[i] = INF;
	}

	table[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ table[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int cur_w = cur.first;
		int cur_v = cur.second;

		if (table[cur_v] < cur_w) {
			continue;
		}

		for (int i = 0; i < graph[cur_v].size(); i++) {
			int nxt_w = graph[cur_v][i].first;
			int nxt_v = graph[cur_v][i].second;

			if (table[nxt_v] > table[cur_v] + nxt_w) {
				table[nxt_v] = table[cur_v] + nxt_w;
				pq.push({ table[nxt_v], nxt_v });
			}
		}
	}

	return table[ed];
}

int main(void) {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b }); // a -> b 가중치 : c
		graph[b].push_back({ c,a }); // b -> a 가중치 : c
	}

	cin >> v1 >> v2;

	
	int course_1 = 0;

	course_1 = calculate_min_range(1, v1) + calculate_min_range(v1, v2) + calculate_min_range(v2, N);

	int course_2 = 0;
	course_2 = calculate_min_range(1, v2) + calculate_min_range(v2, v1) + calculate_min_range(v1, N);

	if (calculate_min_range(1, v1) == INF || calculate_min_range(v1, v2) == INF || calculate_min_range(v2, N) == INF) {
		cout << -1;
	}
	else if (calculate_min_range(1, v2) == INF || calculate_min_range(v2, v1) == INF || calculate_min_range(v1, N) == INF)
	{
		cout << -1;
	}
	else {
		if (course_1 < course_2) {
			cout << course_1;
		}
		else {
			cout << course_2;
		}
	}

}