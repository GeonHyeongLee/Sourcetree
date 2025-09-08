#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int m;

vector<int> nums;
vector<int> per;

void print_num() {
	for (int i = 0; i < per.size(); i++) {
		cout << per[i] << " ";
	}
	cout << "\n";
}

void back_tracking(int cur, int cur_len) {

	if (cur_len == m) {
		print_num();
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		per.push_back(nums[i]);
		back_tracking(cur, cur_len + 1);
		per.pop_back();
	}

}

int main(void) {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	back_tracking(1, 0);
}