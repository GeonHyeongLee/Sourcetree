#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
int visited[100][100];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int>> q;

bool Cango(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    else if (grid[x][y] == 1 || visited[x][y]) {
        return false;
    }
    return true;
}

void BFS() {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (Cango(nx, ny)) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];


    for (int i = 0; i < k; i++) {
        visited[r[i] - 1][c[i] - 1] = 1;
        q.push(make_pair(r[i] - 1, c[i] - 1));
    }

    BFS();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
