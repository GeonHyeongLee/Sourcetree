#include <iostream>
#include <vector>
#include <queue>


using namespace std;


vector<pair<int, int>> graph[5001];
int n;
int question;

int main(void) {

	cin >> n;
	cin >> question;
	
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 0; i < question; i++) {
		vector<bool> visited(5001, false);
		int ans = 0;
		int k, v;
		cin >> k >> v;
		queue<int> q;
		visited[v] = true;
		q.push(v);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i].first;
				if (visited[next]) {
					continue;
				}
				int nx_weight = graph[cur][i].second;
				if (nx_weight >= k) {
					visited[cur] = true;
					ans++;
					q.push(next);
				}
			}
		}
		cout << ans << "\n";
	}

}