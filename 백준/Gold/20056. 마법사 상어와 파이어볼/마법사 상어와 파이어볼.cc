#include <iostream>
#include <vector>

// n의 최대 크기
#define MAX 52

using namespace std;

int N; // 격자 크기 
int M; // 처음 시작 파이어볼 숫자
int K; // 이동 명령 횟수

// 8방위 이동 방향 설정 (dy: 행(y), dx: 열(x))
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0, 1,1,1,0,-1,-1,-1 };

// fireball 구조체 => 행(y), 열(x), 질량, 방향, 속도
struct fireball {
	int y;
	int x;
	int mess;
	int speed;
	int dir;
};

vector<fireball> graph[MAX][MAX];

void boundary_set(int& x, int& y) {
	if (x < 1) x += N;
	if (x > N) x -= N;
	if (y < 1) y += N;
	if (y > N) y -= N;
}

// 이동 방법 설정
void move_fireball(void) {
	vector<fireball> copy_graph[MAX][MAX];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j].empty()) continue;

			for (int k = 0; k < (int)graph[i][j].size(); k++) {
				int m = graph[i][j][k].mess;
				int d = graph[i][j][k].dir;
				int s = graph[i][j][k].speed % N; // 속도는 범위 이상을 넘어서지 않도록 줄여준다
				int y = graph[i][j][k].y;
				int x = graph[i][j][k].x;

				int ny = y + s * dy[d]; // 행(y) ← dy
				int nx = x + s * dx[d]; // 열(x) ← dx
				boundary_set(nx, ny);

				copy_graph[ny][nx].push_back({ ny, nx, m, graph[i][j][k].speed, d });
			}
			// 원본 칸은 비워둠 (다음 단계에서 덮어씀)
		}
	}

	// 1..N 범위만 반영
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = copy_graph[i][j];
		}
	}
}

void sum_fireball(void) {
	vector<fireball> copy_graph[MAX][MAX];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int sz = (int)graph[i][j].size();
			if (sz == 0) {
				continue;
			}
			else if (sz == 1) {
				copy_graph[i][j] = graph[i][j];
			}
			else {
				int sum_mess = 0;
				int sum_speed = 0;
				int even_cnt = 0, odd_cnt = 0;

				for (int k = 0; k < sz; k++) {
					sum_mess += graph[i][j][k].mess;
					sum_speed += graph[i][j][k].speed;
					if (graph[i][j][k].dir % 2 == 0) even_cnt++;
					else odd_cnt++;
				}

				int nm = sum_mess / 5;
				if (nm == 0) {
					// 이 칸은 비워둔다
					continue; // (함수 return 아님!)
				}
				int ns = sum_speed / sz;

				if (even_cnt == sz || odd_cnt == sz) {
					// 모두 짝수 또는 모두 홀수
					copy_graph[i][j].push_back({ i, j, nm, ns, 0 });
					copy_graph[i][j].push_back({ i, j, nm, ns, 2 });
					copy_graph[i][j].push_back({ i, j, nm, ns, 4 });
					copy_graph[i][j].push_back({ i, j, nm, ns, 6 });
				}
				else {
					// 섞여 있음
					copy_graph[i][j].push_back({ i, j, nm, ns, 1 });
					copy_graph[i][j].push_back({ i, j, nm, ns, 3 });
					copy_graph[i][j].push_back({ i, j, nm, ns, 5 });
					copy_graph[i][j].push_back({ i, j, nm, ns, 7 });
				}
			}
		}
	}

	// 1..N 범위만 반영 (한 번만)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = copy_graph[i][j];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	// 기본 입력: graph[y][x]에 저장
	for (int i = 0; i < M; i++) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d;
		graph[y][x].push_back({ y, x, m, s, d });
	}

	// 이동 명령 K번 수행
	for (int i = 0; i < K; i++) {
		move_fireball();
		sum_fireball();
	}

	long long result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < (int)graph[i][j].size(); k++) {
				result += graph[i][j][k].mess;
			}
		}
	}
	cout << result << "\n";
}
