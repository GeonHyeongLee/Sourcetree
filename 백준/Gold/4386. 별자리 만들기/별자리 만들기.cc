#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

#define MAX 101

using namespace std;

int n;
vector<pair<double, double>> stars;

double calculate_dist(int x1, int y1, int x2, int y2) {

	double nx = x2 - x1;
	double ny = y2 - y1;

	return sqrt(pow(nx, 2) + pow(ny, 2));
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		stars.push_back({ a,b });
	}

	vector<pair<double, int>> graph[MAX];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = calculate_dist(stars[i].first, stars[i].second,
				stars[j].first, stars[j].second);
			graph[i].push_back({ dist, j });
			graph[j].push_back({ dist,i });
		}
	}

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

	pq.push({ 0.0, 0 });

	vector<bool> visited(MAX, false);

	int edge_count = 0;
	double min_num = 0;

	while (!pq.empty() && edge_count < n) {
		auto cur = pq.top(); pq.pop();
		double cur_w = cur.first;
		int cur_v = cur.second;

		if (visited[cur_v]) {
			continue;
		}

		visited[cur_v] = true;
		edge_count++;
		min_num += cur_w;

		for (int i = 0; i < graph[cur_v].size(); i++) {
			double nxt_w = graph[cur_v][i].first;
			int nxt_v = graph[cur_v][i].second;

			if (!visited[nxt_v]) {
				pq.push({ nxt_w, nxt_v });
			}
		}
	}

	cout.precision(3);
	cout << min_num;
}