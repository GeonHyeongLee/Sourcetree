#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 505

int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int max_num = 0;

// 상, 하, 좌, 우 이동
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// 'ㅗ', 'ㅜ', 'ㅏ', 'ㅓ' 4가지 모양만 상대 좌표로 정의
// 각 모양의 볼록한 부분을 (0,0) 기준으로 삼음
int t_shapes[4][3][2] = {
    {{-1, 0}, {1, 0}, {0, -1}},  // ㅏ (중심 기준 위, 아래, 왼쪽)
    {{-1, 0}, {1, 0}, {0, 1}},   // ㅓ (중심 기준 위, 아래, 오른쪽)
    {{0, -1}, {0, 1}, {1, 0}},   // ㅗ (중심 기준 왼쪽, 오른쪽, 아래)
    {{0, -1}, {0, 1}, {-1, 0}}   // ㅜ (중심 기준 왼쪽, 오른쪽, 위)
};

// DFS: 'ㅗ' 모양을 제외한 나머지 모양들을 탐색
void dfs(int r, int c, int count, int sum) {
    // 4개의 블록을 모두 선택했을 때
    if (count == 4) {
        max_num = max(max_num, sum);
        return;
    }

    // 상하좌우로 다음 블록을 탐색
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        // 격자판 범위를 벗어나거나 이미 방문한 곳이면 건너뛰기
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc]) {
            continue;
        }

        visited[nr][nc] = true;
        dfs(nr, nc, count + 1, sum + graph[nr][nc]);
        visited[nr][nc] = false; // 백트래킹: 탐색이 끝나면 방문 표시 해제
    }
}


// 'ㅗ' 모양 테트로미노만 별도로 계산하는 함수
void checkTShape(int r, int c) {
    // 4가지 회전된 모양에 대해 시도
    for (int i = 0; i < 4; i++) {
        bool is_valid = true;
        int sum = graph[r][c]; // 중심 블록의 값

        // 중심 블록에 3개의 날개를 붙여봄
        for (int j = 0; j < 3; j++) {
            int nr = r + t_shapes[i][j][0];
            int nc = c + t_shapes[i][j][1];

            // 날개가 격자판을 벗어나면 이 모양은 불가능
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                is_valid = false;
                break;
            }
            sum += graph[nr][nc];
        }

        if (is_valid) {
            max_num = max(max_num, sum);
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    // 격자판의 모든 칸 (i, j)에서 탐색 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 1. DFS 탐색 시작
            visited[i][j] = true;
            dfs(i, j, 1, graph[i][j]);
            visited[i][j] = false;

            // 2. 'ㅗ' 모양 탐색 (현재 위치를 중심점으로)
            checkTShape(i, j);
        }
    }

    cout << max_num;

    return 0;
}