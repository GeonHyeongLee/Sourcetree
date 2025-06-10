#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[10000], to[10000];

vector<int> graph[10001];
bool visited[10001];

int count = 0;

void dfs(int vertex) {
    for (int i = 0; i < graph[vertex].size(); i++) {
        int cur_idx = graph[vertex][i];
        if (!visited[cur_idx]) {
            visited[cur_idx] = true;
            count++;
            dfs(cur_idx);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    visited[1] = true;
    dfs(1);

    cout << count;


    return 0;
}
