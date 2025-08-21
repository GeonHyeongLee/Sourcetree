#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 21

int n;
int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int max_num = 0;


void push(int dir) {
	int copy_graph[MAX][MAX];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy_graph[i][j] = graph[i][j];
		}
	}

	if (dir == 0) {

		for (int i = 0; i < n; i++) {
			vector<int> v;
			for (int j = 0; j < n; j++) {
				if (copy_graph[i][j] != 0) {
					v.push_back(copy_graph[i][j]);
				}
			}
			for (int z = 0; z < v.size(); z++) {
				graph[i][z] = v[z];
			}
			for (int p = v.size(); p < n; p++) {
				graph[i][p] = 0;
			}
		}
	}

	else if (dir == 1) {
		
		for (int i = 0; i < n; i++) {
			// 1 2 0 이라 할 때 오른쪽으로 밀면 0 1 2
			vector<int> v;
			for (int j = 0; j < n; j++) {
				if (copy_graph[i][j] != 0) {
					v.push_back(copy_graph[i][j]);
				}
			}
			for (int p = 0; p < n - v.size(); p++) {
				graph[i][p] = 0;
			}
			int cnt = 0;
			for (int z = n - v.size(); z < n; z++) {
				graph[i][z] = v[cnt];
				cnt++;
			}
		}
	}

	else if (dir == 2) {

		for (int j = 0; j < n; j++) {
			vector<int> v;
			for (int i = 0; i < n; i++) {
				if (copy_graph[i][j] != 0) {
					v.push_back(copy_graph[i][j]);
				}
			}

			for (int z = 0; z < v.size(); z++) {
				graph[z][j] = v[z];
			}
			for (int p = v.size(); p < n; p++) {
				graph[p][j] = 0;
			}
		}
	}

	else if (dir == 3) {
		for (int j = 0; j < n; j++) {
			// 1 2 0 이라 할 때 오른쪽으로 밀면 0 1 2
			vector<int> v;
			for (int i = 0; i < n; i++) {
				if (copy_graph[i][j] != 0) {
					v.push_back(copy_graph[i][j]);
				}
			}
			for (int p = 0; p < n - v.size(); p++) {
				graph[p][j] = 0;
			}
			int cnt = 0;
			for (int z = n - v.size(); z < n; z++) {
				graph[z][j] = v[cnt];
				cnt++;
			}
		}
	}
}


void all_move(int dir) {

	int copy_graph[MAX][MAX];

	// 왼쪽으로 밀기
	if (dir == 0) {
		// 일단 왼쪽으로 숫자 다 밀어준다.
		push(0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copy_graph[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (copy_graph[i][j] == copy_graph[i][j + 1] && visited[i][j] == 0) {
					copy_graph[i][j] *= 2;
					copy_graph[i][j + 1] = 0;
					visited[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = copy_graph[i][j];
			}
		}

		push(0);
	}
	// 오른쪽으로 밀기
	else if (dir == 1) {
		
		push(1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copy_graph[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= 1; j--) {
				if (copy_graph[i][j] == 0) {
					continue;
				}
				
				if (copy_graph[i][j] == copy_graph[i][j - 1] && visited[i][j] == 0) {
					copy_graph[i][j] *= 2;
					copy_graph[i][j - 1] = 0;
					visited[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = copy_graph[i][j];
			}
		}
		push(1);
	}

	// 위로 밀기
	else if (dir == 2) {
		push(2);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copy_graph[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (copy_graph[i][j] == copy_graph[i+1][j] && visited[i][j] == 0) {
					copy_graph[i][j] *= 2;
					copy_graph[i+1][j] = 0;
					visited[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = copy_graph[i][j];
			}
		}


		push(2);
	}

	// 아래로 밀기
	else if (dir == 3) {
		push(3);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copy_graph[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 1; i--) {
				
				if (copy_graph[i][j] == 0) {
					continue;
				}

				if (copy_graph[i][j] == copy_graph[i-1][j] && visited[i][j] == 0) {
					copy_graph[i][j] *= 2;
					copy_graph[i-1][j] = 0;
					visited[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = copy_graph[i][j];
			}
		}
		
		push(3);
	}
}

int find_max_num(void) {
	int mini_max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mini_max_num = max(mini_max_num, graph[i][j]);
		}
	}
	return mini_max_num;
}


void back_tracking(int cnt) {
	if (cnt == 5) {
		max_num = max(max_num, find_max_num());
		return;
	}

	int backup[MAX][MAX];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			backup[i][j] = graph[i][j];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		all_move(dir);
		back_tracking(cnt + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = backup[i][j];
			}
		}
	}
}

int main(void) {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	back_tracking(0);

	cout << max_num;
	
}

