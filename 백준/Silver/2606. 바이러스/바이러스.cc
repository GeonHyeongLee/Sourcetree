#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n; // 컴퓨터의 수
int m; // 컴퓨터 쌍의 수

vector<int> graph[MAX];
vector<bool> visited(MAX);

int main(void) {
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int to = q.front();
		q.pop();

		for (int i = 0; i < graph[to].size(); i++) {
			int go = graph[to][i];
			if (!visited[go]) {
				visited[go] = true;
				q.push(go);
				cnt += 1;
			}
		}
	}
	cout << cnt;
}