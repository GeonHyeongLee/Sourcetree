#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T; // 테스트 케이스 개수


int main(void) {
	cin >> T;

	for (int i = 0; i < T; i++) {

		int N; // 건물 개수
		int K; // 건물 순서 규칙 개수
		int W; // 승리하기 위해 건설해야 할 건물의 번호 W

		cin >> N >> K;
		vector<int> build_time;

		for (int j = 0; j < N; j++) {
			int b_t;
			cin >> b_t;
			build_time.push_back(b_t);
		}

		vector<vector<int>> build_sequence(N);
		vector<int> in_degree(N, 0);
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			build_sequence[x].push_back(y);
			in_degree[y] += 1;
		}

		// 승리 조건 건물 0-index이므로 1 빼줌
		cin >> W;
		W = W - 1;

		vector<int> max_time_table(N, 0);
		queue<int> q;

		for (int j = 0; j < N; j++) {
			if (in_degree[j] == 0) {
				max_time_table[j] = build_time[j];
				q.push(j);
			}
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int j = 0; j < build_sequence[cur].size(); j++) {
				int nxt = build_sequence[cur][j];

				max_time_table[nxt] = max(max_time_table[nxt], max_time_table[cur]);
				in_degree[nxt] -= 1;

				if (in_degree[nxt] == 0) {
					max_time_table[nxt] += build_time[nxt];
					q.push(nxt);
				}
			}
		}

		cout << max_time_table[W] << "\n";
	}
}