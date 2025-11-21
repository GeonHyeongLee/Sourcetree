#include <iostream>
#include <vector>
#include <queue>


#define MAX 1001
#define INF 987654321

using namespace std;

int N;
int M;



int main(void) {
	cin >> N;
	cin >> M;

	vector<pair<int, int>> graph[MAX];

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<bool> visited(MAX, false);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	pq.push({ 0,1 });

	int min_cost = 0;
	int edge_count = 0;

	while (!pq.empty() && edge_count < N) {

		auto cur = pq.top(); pq.pop();
		int cur_w = cur.first;
		int cur_v = cur.second;

		if (visited[cur_v]) {
			continue;
		}

		visited[cur_v] = true;
		min_cost += cur_w;
		edge_count += 1;

		for (int i = 0; i < graph[cur_v].size(); i++) {
			int nxt_w = graph[cur_v][i].first;
			int nxt_v = graph[cur_v][i].second;

			if (!visited[nxt_v]) {
				pq.push({ nxt_w, nxt_v });
			}
		}
	}

	cout << min_cost;


}