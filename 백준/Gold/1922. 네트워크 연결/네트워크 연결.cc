#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 987654321

using namespace std;

int N; // 컴퓨터의 수
int M; // 간선의 수

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// 전체 그래프
	vector<pair<int, int>> graph[MAX];
	// 우선순위 큐
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 방문 여부 확인 -> 방문했다면 더 안해도 되니까
	vector<bool> visited(MAX, false);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	pq.push({ 0,1 }); // 임의의 정점 1에서 시작한다 가정

	int min_cost = 0; // 전체 연결 최소 비용
	int edge_count = 0; // 최종 간선 개수 = N - 1개일 것

	while (!pq.empty() && edge_count < N) {
		auto cur = pq.top(); pq.pop();
		int cur_w = cur.first; // 현재 필요 비용
		int cur_v = cur.second; // 현재 위치 정점

		// 만약 이미 방문한 정점이라면 continue
		if (visited[cur_v]) {
			continue;
		}

		// 그렇지 않다면 edge_count 더하고, visited 표시하고, min_cost더함
		visited[cur_v] = true;
		edge_count++;
		min_cost += cur_w;

		// 그리고 해당 정점과 연결된 정점들 모두에서 방문 안된 곳으로 이동
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