#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 21
using namespace std;

int n;
int graph[MAX][MAX];
int copy_graph[MAX][MAX];
int visited[MAX][MAX];
int max_num = 0;

void visited_init(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

void copy_graph_init(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy_graph[i][j] = graph[i][j];
		}
	}
}

void push(int dir) {	
	if (dir == 0) {
		for (int i = 0; i < n; i++) {
			vector<int> v;

			for (int j = 0; j < n; j++) {
				if (graph[i][j] != 0) {
					v.push_back(graph[i][j]);
				}
			}

			for (int p = 0; p < v.size(); p++) {
				graph[i][p] = v[p];
			}
			for (int q = v.size(); q < n; q++) {
				graph[i][q] = 0;
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			vector<int> v;
			for (int j = 0; j < n; j++) {
				if (graph[i][j] != 0) {
					v.push_back(graph[i][j]);
				}
			}
			int cnt = 0;
			for (int p = 0; p < n - v.size(); p++) {
				graph[i][p] = 0;
			}

			for (int q = n - v.size(); q < n; q++) {
				graph[i][q] = v[cnt];
				cnt++;
			}

		}
	}
	else if (dir == 2) {
		for (int j = 0; j < n; j++) {
			vector<int> v;

			for (int i = 0; i < n; i++) {
				if (graph[i][j] != 0) {
					v.push_back(graph[i][j]);
				}
			}

			for (int p = 0; p < v.size(); p++) {
				graph[p][j] = v[p];
			}
			for (int q = v.size(); q < n; q++) {
				graph[q][j] = 0;
			}
		}
	}
	else if (dir == 3) {
		for (int j = 0; j < n; j++) {
			vector<int> v;
			for (int i = 0; i < n; i++) {
				if (graph[i][j] != 0) {
					v.push_back(graph[i][j]);
				}
			}
			int cnt = 0;
			for (int p = 0; p < n - v.size(); p++) {
				graph[p][j] = 0;
			}

			for (int q = n - v.size(); q < n; q++) {
				graph[q][j] = v[cnt];
				cnt++;
			}

		}
	}
}

void all_move(int dir) {

	// 좌
	if (dir == 0) {
		push(dir);


		visited_init();
		copy_graph_init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1; j++) {
				if (copy_graph[i][j] == copy_graph[i][j + 1] && !visited[i][j]) {
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

		push(dir);
	}
	// 우
	else if (dir == 1) {
		push(dir);

		visited_init();
		copy_graph_init();

		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= 1; j--) {
				if (copy_graph[i][j] == copy_graph[i][j - 1] && !visited[i][j]) {
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

		push(dir);
	}
	// 상
	else if (dir == 2) {
		push(dir);

		visited_init();
		copy_graph_init();

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (copy_graph[i][j] == copy_graph[i+1][j] && !visited[i][j]) {
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

		push(dir);
	}
	// 하
	else if (dir == 3) {
		push(dir);

		visited_init();
		copy_graph_init();

		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 1; i--) {
				if (copy_graph[i][j] == copy_graph[i-1][j] && !visited[i][j]) {
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


		push(dir);
	}
}

int calculate_max(void) {
	int graph_max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] > max_num) {
				max_num = graph[i][j];
			}
		}
	}
	return graph_max_num;
}

void back_tracking(int cnt) {
	if (cnt == 5) {
		int num = calculate_max();

		max_num = max(max_num, num);
		return;
	}

	int copy_graph[MAX][MAX];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy_graph[i][j] = graph[i][j];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		all_move(dir);

		back_tracking(cnt + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = copy_graph[i][j];
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

