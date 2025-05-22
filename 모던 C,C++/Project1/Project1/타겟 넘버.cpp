#include <string>
#include <vector>

using namespace std;

int count = 0;

void dfs(vector<int>& numbers, int target, int cur_index, int value) {

    int len_num = numbers.size();

    if (cur_index == len_num) {
        if (target == value) {
            count++;
        }

        return; // *�߿�* -> value != target �϶��� return ����� ��� �Ѿ �� ����
    }

    dfs(numbers, target, cur_index + 1, value + numbers[cur_index]);
    dfs(numbers, target, cur_index + 1, value - numbers[cur_index]);
}

int solution(vector<int> numbers, int target) {
    count = 0;

    dfs(numbers, target, 0, 0);
    return count;
}