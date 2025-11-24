#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 가수의 수
int M; // 보조 PD의 수

int sing; // 담당 가수
int first; // 제일 앞 순서 (in_degree =  0) 
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<vector<int>> singers(N);
	vector<int> in_degree(N, 0);

	for (int i = 0; i < M; i++) {
		cin >> sing >> first;
		first = first - 1;
		for (int j = 0; j < sing - 1; j++) {
			int num;
			cin >> num;
			num = num - 1;
			singers[first].push_back(num);
			in_degree[num]++;
			first = num; // 이제 first를 수정해서 singers[first] 뒤에 연결되는게
			// 1 -> 4 -> 3 이었다면 1->4했으니까 이제 4 -> 3으로 연결할 수 있게 바꿔준다
		}
	}

	queue<int> q;

	for (int i = 0; i < N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> result;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (in_degree[cur] == 0) {
			result.push_back(cur);
		}

		for (int i = 0; i < singers[cur].size(); i++) {
			int nxt = singers[cur][i];
			in_degree[nxt] -= 1;

			if (in_degree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}
	
	if (result.size() != N) {
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] + 1 << "\n";
		}
	}
}