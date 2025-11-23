#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>


#define MAX 1001

using namespace std;

int N; // 우주신 개수
int M; // 이미 연결된 신들과의 통로 개수

vector<pair<int, int>> positions;

double calculate_dist(int x1, int y1, int x2, int y2) {
	double nx = x1 - x2;
	double ny = y1 - y2;

	return sqrt(pow(nx, 2) + pow(ny, 2));
}


int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int st, ed;
		cin >> st >> ed;
		positions.push_back({ st,ed });
	}

	vector<pair<double, int>> graph[MAX];


	// 일단 모든 통로를 graph에 추가한다
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double dist = calculate_dist(positions[i].first, positions[i].second,
				positions[j].first, positions[j].second);
			graph[i].push_back({ dist,j });
			graph[j].push_back({ dist,i });
		}
	}

	// 그럼 현재 그래프에는 우주신 + 빵상 아줌마까지 모든 정점 간 연결 거리 있을 것
	// 여기서 우리가 구하고 싶은건 가장 짧은 통로 길이 합 = 스패닝 트리

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

	// 해당 정점 방문 여부 확인
	vector<bool> visited(N, false);

	// 만약 이미 연결된 간선이라면? 최소 스패닝 트리에 추가한다

	for (int i = 0; i < M; i++) {
		int st, ed;
		cin >> st >> ed;
		st = st - 1;
		ed = ed - 1;

		graph[st].push_back({ 0.0, ed });
		graph[ed].push_back({ 0.0, st });
	}

	pq.push({ 0.0,0 });

	double min_cost = 0.0;
	int edge_count = 0;

	while (!pq.empty() && edge_count < N) {
		auto cur = pq.top(); pq.pop();
		double cur_w = cur.first;
		int cur_v = cur.second;

		if (visited[cur_v]) {
			continue;
		}

		visited[cur_v] = true;
		edge_count++;
		min_cost += cur_w;

		for (int i = 0; i < graph[cur_v].size(); i++) {
			double nxt_w = graph[cur_v][i].first;
			int nxt_v = graph[cur_v][i].second;

			if (!visited[nxt_v]) {
				pq.push({ nxt_w, nxt_v });
			}
		}
	}

	
	cout << fixed << setprecision(2) << min_cost;
	
}