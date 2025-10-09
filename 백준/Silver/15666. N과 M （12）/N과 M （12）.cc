#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n;
int m;
vector<int> nums;
vector<int> result;
set<int> s;

void print_result() {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void back_tracking(int cnt,int cur_num, int len) {
	if (cnt == len) {
		print_result();
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= cur_num) {
			cur_num = nums[i];
			result.push_back(cur_num);
			back_tracking(cnt + 1, cur_num, len);
			result.pop_back();
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (auto& v : s) {
		nums.push_back(v);
	}

	sort(nums.begin(), nums.end());

	//for (int i = 0; i < nums.size(); i++) {
	//	cout << nums[i] << " ";
	//}
	//cout << "\n";
	back_tracking(0, nums[0], m);
}