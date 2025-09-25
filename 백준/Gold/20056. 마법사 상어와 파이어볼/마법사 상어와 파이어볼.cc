#include <iostream>
#include <vector>

#define MAX 52

using namespace std;

// 2차원 배열에서 행은 y, 열은 x
// 행(row) = 세로 = y
// 열(col) = 가로 = x
// 그러니까 2차원 배열 graph는 graph[ny][nx]
// 그냥 간단하게 평소 하던 x,y를 모두 뒤집었다고 생각하자


int N; // 격자 크기
int M; // 파이어볼 개수
int K; // 명령 수행 횟수

int dy[8] = { -1,-1,0,1,1,1,0,-1 }; // 행
int dx[8] = { 0,1,1,1,0,-1,-1,-1 }; // 열

struct fireball {
	int y; // 행
	int x; // 열
	int mass; // 질량
	int speed; // 속도
	int direction; // 방향
};


// graph[행][열]  
// 행 : 아래로 내려갈 수록 커짐 
// 열 : 옆으로 갈 수록 커짐
vector<fireball> graph[MAX][MAX];



void boundary_set(int& nx, int& ny) {
	if (nx < 1) {
		nx += N;
	}
	if (nx > N) {
		nx -= N;
	}
	if (ny < 1) {
		ny += N;
	}
	if (ny > N) {
		ny -= N;
	}
}

void move_fireball() {
	vector<fireball> copy_graph[MAX][MAX];

	for (int y = 1; y <= N; y++) { // 행
		for (int x = 1; x <= N; x++) { // 열
			if (!graph[y][x].empty()) {
				for (int k = 0; k < graph[y][x].size(); k++) {
					
					int m = graph[y][x][k].mass;
					int s = graph[y][x][k].speed;
					
					// 속도는 너무 빠르면 범위를 벗어나버림 최대 크기 격자 크기로 제한
					s %= N;
					
					int d = graph[y][x][k].direction;

					int nx = graph[y][x][k].x + s * dx[d]; // 다음 열
					int ny = graph[y][x][k].y + s * dy[d]; // 다음 행 

					boundary_set(nx, ny);

					//cout << "바뀐 좌표값 : " << ny << " " << nx << "\n";
					copy_graph[ny][nx].push_back({ ny, nx, m, graph[y][x][k].speed,d });
				}
				graph[y][x].clear();
			}
			else {
				continue;
			}
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			graph[y][x] = copy_graph[y][x];
		}
	}
}

void sum_fireball() {
	vector<fireball> copy_graph[MAX][MAX];

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (graph[y][x].size() == 0) {
				continue;
			}
			else if (graph[y][x].size() == 1) {
				copy_graph[y][x] = graph[y][x];
				continue;
			}
			else {
				int sum_m = 0;
				int sum_s = 0;
				int ball_cnt = 0;
				int ball_odd_cnt = 0;
				int ball_even_cnt = 0;

				for (int k = 0; k < graph[y][x].size(); k++) {
					int m = graph[y][x][k].mass;
					int s = graph[y][x][k].speed;
					int d = graph[y][x][k].direction;

					sum_m += m;
					sum_s += s;
					ball_cnt += 1;

					if (d % 2 == 0) {
						ball_even_cnt += 1;
					}
					else {
						ball_odd_cnt += 1;
					}

				}

				sum_m /= 5;
				sum_s /= ball_cnt;

				if (sum_m == 0) {
					continue;
				}

				if (ball_cnt == ball_odd_cnt || ball_cnt == ball_even_cnt) {
					for (int t = 0; t < 4; t++) {
						copy_graph[y][x].push_back({ y,x,sum_m,sum_s, 2 * t });
					}
				}
				else {
					for (int t = 0; t < 4; t++) {
						copy_graph[y][x].push_back({ y,x,sum_m,sum_s, 2 * t + 1 });
					}
				}
			}
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			graph[y][x] = copy_graph[y][x];
		}
	}
}

int main(void) {
	cin >> N >> M >> K;
	
	for (int i = 0; i < M; i++) {
		int y, x, m, s, d; // r : 행, c : 열, m : 질량, s : 속도, d : 방향
		cin >> y >> x >> m >> s >> d;
		graph[y][x].push_back({ y,x,m,s,d });
	}


	for (int i = 0; i < K; i++) {
		move_fireball();
		sum_fireball();
	}

	long long result = 0;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (!graph[y][x].empty()) {
				for (int k = 0; k < graph[y][x].size(); k++) {
					result += graph[y][x][k].mass;
				}
			}
		}
	}

	cout << result << "\n";
}