#include <iostream>
#include <vector>
#include <queue>
#include <cmath>


#define MAX 101

using namespace std;
int n;
vector<pair<double, double>> stars;


double get_distance(double x1, double y1, double x2, double y2) {
	double dx = x2 - x1;
	double dy = y2 - y1;

	return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		stars.push_back({ a,b });
	}

	vector<pair<double, int>> graph[MAX];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = get_distance(stars[i].first, stars[i].second, 
				stars[j].first, stars[j].second);

			graph[i].push_back({ dist,j });
			graph[j].push_back({ dist,i });
		}
	}
		
	priority_queue < pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	vector<bool> visited(MAX, false);

	pq.push({ 0.0 , 0 });

	int edge_count = 0;
	double min_cost = 0;

	while (!pq.empty() && edge_count < n) {
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

	cout.precision(3);

	cout << min_cost;
}