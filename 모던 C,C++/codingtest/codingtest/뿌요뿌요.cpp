#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
int grid[100][100];
int visited[100][100];


int count_num;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool Cango(int x, int y, int k) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    else if (visited[x][y] || grid[x][y] != k) {
        return false;
    }
    return true;
}

void dfs(int x, int y, int k) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (Cango(nx, ny, k)) {
            count_num++;
            visited[nx][ny] = 1;
            dfs(nx, ny, k);
        }
    }
}

void cleanvisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    cin >> n;

    vector<int> grid_num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            grid_num.push_back(grid[i][j]);
        }
    }


    // set으로 바꿨을 때는 index를 사용할 수 없으므로 다시 vector로 바꿔줘야 한다!!!

    set<int> s(grid_num.begin(), grid_num.end());

    vector<int> v(s.begin(), s.end()); // 1  2  3  4

    vector<int> real_boom;
    vector<int> count_boom;

    for (int k = 0; k < v.size(); k++) {
        vector<int> Block;
        cleanvisited();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Cango(i, j, v[k])) {
                    count_num = 1;
                    visited[i][j] = 1;
                    dfs(i, j, v[k]);
                    Block.push_back(count_num);
                    count_boom.push_back(count_num);
                }
            }
        }
        int max_boom = 0;

        for (int i = 0; i < Block.size(); i++) {
            if (Block[i] > max_boom) {
                max_boom = Block[i];
            }
        }
        real_boom.push_back(max_boom);

    }

    int bomb_count = 0;
    for (int i = 0; i < count_boom.size(); i++) {
        if (count_boom[i] >= 4) {
            bomb_count++;
        }
    }

    int real_max_boom = 0;
    for (int i = 0; i < real_boom.size(); i++) {
        if (real_boom[i] > real_max_boom) {
            real_max_boom = real_boom[i];
        }
    }

    cout << bomb_count << " " << real_max_boom;



    return 0;
}
