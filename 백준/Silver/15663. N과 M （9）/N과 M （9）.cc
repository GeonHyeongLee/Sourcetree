#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;

vector<int> nums;

vector<int> permutation;

vector<bool> used(9, false);

void print_permutation() {
	for (int i = 0; i < permutation.size(); i++) {
		cout << permutation[i] << " ";
	}
	cout << "\n";
}

void find_permutation(vector<int>& nums, int num, int num_len) {
	if (num_len == m) {
		print_permutation();
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (!used[i]) {
			// 0 0 1 1 2
			if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
				continue;
			}
			permutation.push_back(nums[i]);
			used[i] = true;
			find_permutation(nums, nums[i], num_len + 1);

			permutation.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	find_permutation(nums, nums[0], 0);
}