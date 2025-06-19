#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[100][100];
int visited[100][100];

queue<pair<int, int>> q;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool Cango(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    else if (visited[x][y] || a[x][y] == 0) {
        return false;
    }
    return true;
}

void bfs() {
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
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    bfs();

    if (visited[n - 1][m - 1] == 1) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
