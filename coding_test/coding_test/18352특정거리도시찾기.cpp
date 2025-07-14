#include <iostream>
#include <queue>

using namespace std;

#define MAX 300001
#define INF 987654321

int d[MAX];
vector<int> graph[MAX];

int main(void) {
	int n, m, k, x;
	cin >> n >> m >> k >> x;

	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	d[x] = 0;

	// graph[1] = 2,3 graph[2] = 3,4
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i];
			if (d[nxt] > d[cur] + 1) {
				d[nxt] = d[cur] + 1;
				q.push(nxt);
			}
		}
	}


	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << "\n";
			count += 1;
		}
	}
	if (count == 0) {
		cout << -1 << "\n";
	}
}