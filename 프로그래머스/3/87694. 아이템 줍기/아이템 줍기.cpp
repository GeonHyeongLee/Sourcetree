#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MAX 110

// 전체 그래프를 -1로 채움
int graph[MAX][MAX];
int visited[MAX][MAX];

// 네 방위
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

// 결과 따라가기
int result[MAX][MAX];

int bfs(int characterX, int characterY, int itemX, int itemY) {
    queue<pair<int,int>> q; 
    visited[characterX][characterY] = 1;
    q.push({characterX,characterY});
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        if (cur_x == itemX && cur_y == itemY) {
                return result[cur_x][cur_y];
            }
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (visited[nx][ny] == true) {
                continue;
            }
            if (graph[nx][ny] == -1 || visited[nx][ny]) {
                continue;
            }
            if (graph[nx][ny] == 1 && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                result[nx][ny] = result[cur_x][cur_y] + 1;
                q.push({nx,ny});
                printf("root : nx -> %d, ny -> %d\n", nx, ny);
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    for (int i= 0; i < rectangle.size(); i++) {
        int start_x = rectangle[i][0] * 2;
        int start_y = rectangle[i][1] * 2;
        int end_x = rectangle[i][2] * 2;
        int end_y = rectangle[i][3] * 2;
        
        // 사각형의 각 변은 이동 가능 상태로 판별 = 값 1부여
        
        // 아래
        for (int i = start_x; i <= end_x; i++) {
            graph[i][start_y] = 1;
        }
        // 오른쪽
        for (int j = start_y; j <= end_y; j++) {
            graph[end_x][j] = 1;
        }
        // 왼쪽
        for (int j = start_y; j <= end_y; j++) {
            graph[start_x][j] = 1;
        }
        // 위쪽
        for (int i = start_x; i <= end_x; i++) {
            graph[i][end_y] = 1;
        }
    }
    
    for (int i= 0; i < rectangle.size(); i++) {
        int start_x = rectangle[i][0] * 2;
        int start_y = rectangle[i][1] * 2;
        int end_x = rectangle[i][2] * 2;
        int end_y = rectangle[i][3] * 2;
        
        for (int i = start_x + 1; i < end_x; i++) {
            for (int j = start_y + 1; j < end_y; j++) {
                graph[i][j] = -1;
            }
        }
    }
    
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
    
    int real_result = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return real_result / 2;
}