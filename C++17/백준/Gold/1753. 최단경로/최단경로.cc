#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 무한대를 표현할 값. 그래프의 최대 거리보다 훨씬 큰 수로 설정
#define INF 1e9

// graph[i]에는 i번 정점에서 갈 수 있는 (목적지 정점, 가중치)의 쌍이 들어감
vector<pair<int, int>> graph[20001];

// d[i]는 시작점에서 i번 정점까지의 최단 거리
int d[20001];

// 오름차순 우선순위 큐 (가중치가 작은 것부터 나오게 함)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e, st; // v: 정점 개수, e: 간선 개수, st: 시작 정점 번호
	cin >> v >> e;
	cin >> st;

	// 간선 정보 입력
	for (int i = 0; i < e; i++) {
		int u, v, w; // u: 출발 정점, v: 도착 정점, w: 가중치
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	// 최단 거리 배열 초기화 (INF로 채움)
	fill(d, d + v + 1, INF);
	d[st] = 0; // 시작점까지의 거리는 0

	// 시작 정점을 우선순위 큐에 넣음 (가중치, 정점번호)
	pq.push({ d[st], st });

	while (!pq.empty()) {
		// 큐에서 가장 거리가 짧은 정점을 꺼냄
		auto cur = pq.top(); pq.pop();
		// cur.first = 현재까지 거리, cur.second = 현재 정점 번호
		int dist = cur.first;
		int now = cur.second;

		// 만약 이미 저장된 최단거리보다 크다면 무시 (이미 처리된 값)
		if (d[now] < dist) continue;

		// now 정점에서 갈 수 있는 모든 이웃 정점들을 확인
		for (int i = 0; i < graph[now].size(); i++) {
			// graph[now][i]는 (도착정점, 가중치)
			int nxt = graph[now][i].first;
			int cost = graph[now][i].second;

			// 만약 now를 거쳐서 nxt로 가는 게 더 짧다면 갱신
			if (d[nxt] > d[now] + cost) {
				d[nxt] = d[now] + cost; // 최단 거리 갱신
				pq.push({ d[nxt], nxt }); // 큐에 넣음
			}
		}
	}

	// 결과 출력
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) {
			cout << "INF" << "\n"; // 갈 수 없는 경우
		}
		else {
			cout << d[i] << "\n";
		}
	}
}
