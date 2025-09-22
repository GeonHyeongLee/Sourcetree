#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int k;
string num;
vector<char> nums;

// 앞에서부터 k개가 남아있는 동안
// 다음으로 들어오는 숫자가 더 크면 stack.pop()
// 그렇게 끝냈는데 k가 남아있다면 이번에는 뒤에서부터 시작
// 다음으로 들어오는 숫자가 더 크면 stack.pop()
// 이렇게 해서 k가 0이 되면 종료
// 종료되었을 때 남아있는 숫자들로 이루어진 숫자가 가장 클 것

int main(void) {
	cin >> n >> k;
	cin >> num;

	for (char v_num : num) {
		// k가 0보다 큰 상황이고, nums은 비어있지 않고,
		// nums의 맨 뒤에 숫자가 새로 들어온 v_num보다 작을 때
		// nums의 맨뒤를 pop한다
		while (k > 0 && !nums.empty() && nums.back() < v_num) {
			nums.pop_back();
			k--;
		}
		nums.push_back(v_num);
	}

	while (k > 0) {
		nums.pop_back();
		k--;
	}

	for (auto v_num : nums) {
		cout << v_num;
	}
}

// 왜 k가 남아서 뒤에서부터 지울 때는 숫자를 고려해서 지울 필요가 없을까?
// 왜냐하면 앞에서 지울 때 이미 순서대로 만들었기 떄문이다
// 1,9,2,4라면 9,4가 되어있을 것이다

