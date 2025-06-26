// 풀이 방법
// 트리를 만드는 건 dfs or bfs로 가능하다
// 나는 dfs를 선택해서 문제를 풀었다.
// dfs(int v)로 제일 처음은 루트 노드를 넣어주면 되겠다
// visited[]를 사용해서 방문한 정점은 방문하지 않는다
// if (Cango())는 그냥 방문하지 않았으면 방문하면 되겠다.
// 부모 노드를 구하고 싶으면 그냥 dfs로 들어가기 전에 따로 값을 저장해준다.

// 시간 초과 조심할 것!!! 
// 1. visited를 int로 쓰면 bool에 비해 시간 초과가 날 가능성이 높아진다!!
// 2. endl보다는 "\n"을 사용하자!
// 3. ios::sync_with_stdio(false);
// 4. cin.tie(NULL)



#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001


vector<int> v[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int c) {
	visited[c] = true;

	for (int i = 0; i < v[c].size(); i++) {
		int num = v[c][i];
		if (!visited[num]) {
			parent[num] = c;
			dfs(num);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}