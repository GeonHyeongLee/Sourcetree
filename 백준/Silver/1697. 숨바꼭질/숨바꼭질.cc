#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 100001
int n, k; // n : 수빈, k : 동생

// 걷는다 x-1 , x+1
// 순간이동 2 * x
int result[MAX];
bool visited[MAX];


void bfs(int st) {

	queue<int> q;
	q.push(st);
	visited[st] = true;
	result[st] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) {
			return;
		}


		int dx[3] = { x + 1 ,x - 1, x * 2 };
		
		for (int i = 0; i < 3; i++) {
			int nx = dx[i];
			if (nx < 0 || nx >= MAX)
				continue;
			if (visited[nx]) {
				continue;
			}
			visited[nx] = true;
			result[nx] = result[x] + 1;
			q.push(nx);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	bfs(n);
	cout << result[k];
}