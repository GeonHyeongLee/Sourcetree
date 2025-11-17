#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 987654321

using namespace std;

int n;
int m;

vector<pair<int, int>> graph[MAX];

int st, ed;

int main(void) {
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({w,v });
	}

	cin >> st >> ed;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	int table[MAX];

	for (int i = 1; i <= n; i++) {
		table[i] = INF;
	}

	table[st] = 0;

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

	//for (int i = 1; i <= n; i++) {
	//	cout << table[i] << "\n";
	//}
	cout << table[ed];

}