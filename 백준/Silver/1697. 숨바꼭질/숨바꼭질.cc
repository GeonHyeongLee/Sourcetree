#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

int n, k;
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 1 0 0 
// 1 2 
// 5 -> (4,6,10) => (4,1),(6,1),(10,1)
// (4,6,10) => (3,8),(7,12),(9,11,20) => (3,7,8,9,11,12,20 = 2)
// 
int result[MAX];
bool visited[MAX];

int min_num = 987654321;
int cnt = 0;

void bfs(int num) {
	queue<int> q;
	q.push(num);
	visited[num] = true;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		
		if (x == k) {
			return;
		}

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0) {
				nx = x * 2;

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
			else if (i == 1) {
				nx = x + 1;
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
			else if (i == 2) {
				nx = x - 1;
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
}

int main(void) {
	cin >> n >> k;

	bfs(n);

	//for (int i = 0; i <= 100; i++) {
	//	cout << result[i] << "\n";
	//}

	cout << result[k];
}