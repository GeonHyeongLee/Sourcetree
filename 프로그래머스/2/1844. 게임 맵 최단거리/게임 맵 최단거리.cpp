#include<vector>
using namespace std;

#define MAX 101

int visited[MAX][MAX];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool Cango(int x, int y, int n, int m, vector<vector<int>> &maps) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    else if (maps[x][y] == 0 || visited[x][y]) {
        return false;
    }
    return true;
}

void dfs(int x, int y, int n, int m, int& answer, vector<vector<int>> &maps) {
        
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (Cango(nx,ny,n,m, maps)) {
            answer+=1;
            dfs(nx,ny,n,m, answer, maps);
        }
    }
        
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    dfs(0,0,n,m,answer, maps);
    
    return answer;
}