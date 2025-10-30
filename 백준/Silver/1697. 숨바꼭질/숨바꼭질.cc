#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int n, k;

int result[MAX];
bool visited[MAX];

void bfs(int num) {
	queue<int> q;
	q.push(num);
	visited[num] = true;

	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == k) {
			return;
		}
		int nxt_position[3] = {x + 1, x - 1,x * 2};

		for (auto nx : nxt_position) {
			if (nx < 0 || nx >= MAX) {
				continue;
			}
			if (visited[nx]) {
				continue;
			}
			q.push(nx);
			visited[nx] = true;
			result[nx] = result[x] + 1;
		}
	}
}

int main(void) {
	cin >> n >> k;

	bfs(n);

	cout << result[k];
}