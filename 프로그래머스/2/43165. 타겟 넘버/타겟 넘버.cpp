#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> &numbers, int cur_idx, int num, int idx_len, int target) {
    if (cur_idx == idx_len) {
        if (num == target) {
            answer += 1;
        }
        return;
    }
    
    dfs(numbers, cur_idx + 1, num + numbers[cur_idx], idx_len, target);
    dfs(numbers, cur_idx + 1, num - numbers[cur_idx], idx_len, target);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, 0, 0, numbers.size(), target);
    return answer;
}