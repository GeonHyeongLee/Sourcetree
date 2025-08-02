#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<bool>> visited;

vector<pair<int,int>> bfs(vector<vector<int>>& graph, int x, int y, int target) {
    queue<pair<int,int>> q;
    vector<pair<int,int>> piece;
    q.push({x,y});
    piece.push_back({x,y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()) {
                continue;
            }
            else if (visited[nx][ny] || graph[nx][ny] != target) {
                continue;
            }
            else if (graph[nx][ny] == target) {
                visited[nx][ny] = true;
                q.push({nx,ny});
                piece.push_back({nx,ny});
            }
        }
    }
    return piece;
}

void normalize(vector<pair<int,int>> &piece) {
    sort(piece.begin(), piece.end());
    auto cur = piece[0];
    int first_x = cur.first;
    int first_y = cur.second;
    
    for (int i = 0; i < piece.size(); i++) {
        piece[i].first -= cur.first;
        piece[i].second -= cur.second;
    }
}

void rotate(vector<pair<int,int>> &piece) {
    for (int i = 0; i < piece.size(); i++) {
        int tmp = piece[i].first;
        piece[i].first = piece[i].second;
        piece[i].second = -tmp;
    }
    normalize(piece);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    vector<vector<bool>> v = vector<vector<bool>>(game_board.size(), vector<bool>(game_board[0].size(), false));
    
    vector<vector<pair<int,int>>> empty_blocks;
    vector<vector<pair<int,int>>> puzzles;
    
    visited = v;
    
    // // visited 배열 잘 들어갔는지 확인 (완료)
    // for (int i = 0; i < game_board.size(); i++) {
    //     for (int j = 0; j < game_board[0].size(); j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[0].size(); j++) {
            if (game_board[i][j] == 0 && visited[i][j] == false) {
                empty_blocks.push_back(bfs(game_board,i,j,0));
            }
        }
    }
    
    visited = v;
    
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            if (table[i][j] == 1 && visited[i][j] == false) {
                puzzles.push_back(bfs(table,i,j,1));
            }
        }
    }
    
    // // empty_blocks에 empty_block이 잘 들어갔는지 확인(완료)
    // for (int i = 0; i < empty_blocks[0].size(); i++) {
    //     auto cur = empty_blocks[0][i];
    //     int test_x = cur.first;
    //     int test_y = cur.second;
    //     cout << test_x << " " << test_y << "\n";
    // }
    // cout << "\n";
    // // puzzles에 puzzle이 잘 들어갔는지 확인(완료)
    // for (int i = 0; i < puzzles[0].size(); i++) {
    //     auto cur = puzzles[0][i];
    //     int test_x = cur.first;
    //     int test_y = cur.second;
    //     cout << test_x << " " << test_y << "\n";
    // }
    // return answer;
    
    for (int i = 0; i < empty_blocks.size(); i++) {
        normalize(empty_blocks[i]);
    }
    
    for (int i = 0; i < puzzles.size(); i++) {
        normalize(puzzles[i]);
    }
    
    // // normalize 잘 되는지 확인(완료)
    // for (int i = 0; i < empty_blocks[0].size(); i++) {
    //     auto cur = empty_blocks[0][i];
    //     cout << cur.first << " " << cur.second << "\n";
    // }
    
    int answer = 0;
    vector<bool> is_puzzle_used(puzzles.size(), false);
    
    for (auto empty_block : empty_blocks) {
        
        bool matched = false;
        
        for (int i = 0; i < puzzles.size(); i++) {
            if (is_puzzle_used[i] == true) {
                continue;
            }
            
            vector<pair<int,int>> puzzle_copy = puzzles[i];
            for (int dir = 0; dir < 4; dir++) {
                if (empty_block == puzzle_copy) {
                    is_puzzle_used[i] = true;
                    answer += puzzles[i].size();
                    matched = true;
                    break;
                }                
                rotate(puzzle_copy);
            }
            if (matched == true) break;
        }
    }

    return answer;
}