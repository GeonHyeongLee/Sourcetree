#include <iostream>
#include <vector>
#include <algorithm>
// num_arr vector로 썼으면 .push_back()로 넣는 거 잊지말기!!
// 재귀로 넣을 때 바로 그냥 cur자리에 num_arr[i]넣는게아니라
// cur= num_arr[i], cur 넣는게맞다...

// 중요한건 백트래킹의 핵심은
// .push_back()  재귀 .pop_back()을 해주는 것이다.

using namespace std;

int N, M;

vector<int> num_arr;
vector<int> result;

void printnum(void) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void find_permutation(int cur, int count) {

	if (count == M) {
		printnum();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (num_arr[i] >= cur) {
			cur = num_arr[i];
			result.push_back(cur);
			find_permutation(cur, count + 1);
			result.pop_back();
		}
	}
}

int main(void) {
	cin >> N >> M;
	
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num_arr.push_back(a);
	}

	sort(num_arr.begin(), num_arr.end());

	find_permutation(num_arr[0], 0);

	return 0;
}