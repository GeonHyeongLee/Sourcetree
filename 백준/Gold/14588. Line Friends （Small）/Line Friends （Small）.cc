#include <iostream>
#include <vector>

using namespace std;

#define MAX 350
#define INF 1000001

int n; // 선분 개수
int q; // 질문 개수

int min_st = 1000001;
int max_end = -1000001;


int main(void) {
	cin >> n;
	
	vector<pair<int, int>> lines;
	
	vector<vector<int>> table(n+1, vector<int>(n+1, INF));

	for (int i = 0; i < n; i++) {
		int L, R;
		cin >> L >> R;
		lines.push_back({ L,R });
	}


	// lines[i][0] 가장 작은 값
	// lines[i][sz-1] 가장 큰 값
	// 가장 작은 값이 lines[j][sz_j-1] 비교할 대상의 가장 큰 값보다 같거나 작을 때
	// 가장 큰 값이 lines[j][0] 비교할 대상의 가장 작은 값보다 같거나 클 때
	// 위 두 조건 중 하나라도 만족한다면 거리 1의 친구 사이이다.


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			if (lines[i].first <= lines[j].second && lines[i].second >= lines[j].first) {
				table[i][j] = 1;
				table[j][i] = 1;
			}
		}
	}




	// 자기 자신으로의 이동 거리는 0으로 초기화한다
	for (int i = 0; i < n; i++) {
		table[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (table[i][k] == INF) continue;
			for (int j = 0; j < n; j++) {
				if (table[k][j] == INF) continue;
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
			}
		}
	}
	

	cin >> q;

	for (int i = 0; i < q; i++) {
		int a;
		int b;
		cin >> a >> b;
		int result = table[a-1][b-1];
		if (result == INF) {
			cout << "-1 " << "\n";
		}
		else {
			cout << result << "\n";
		}
	}

}