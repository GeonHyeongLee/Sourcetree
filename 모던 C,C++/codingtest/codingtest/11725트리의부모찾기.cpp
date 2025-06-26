// Ǯ�� ���
// Ʈ���� ����� �� dfs or bfs�� �����ϴ�
// ���� dfs�� �����ؼ� ������ Ǯ����.
// dfs(int v)�� ���� ó���� ��Ʈ ��带 �־��ָ� �ǰڴ�
// visited[]�� ����ؼ� �湮�� ������ �湮���� �ʴ´�
// if (Cango())�� �׳� �湮���� �ʾ����� �湮�ϸ� �ǰڴ�.
// �θ� ��带 ���ϰ� ������ �׳� dfs�� ���� ���� ���� ���� �������ش�.

// �ð� �ʰ� ������ ��!!! 
// 1. visited�� int�� ���� bool�� ���� �ð� �ʰ��� �� ���ɼ��� ��������!!
// 2. endl���ٴ� "\n"�� �������!
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