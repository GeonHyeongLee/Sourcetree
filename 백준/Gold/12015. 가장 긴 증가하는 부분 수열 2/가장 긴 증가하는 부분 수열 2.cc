#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> nums(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<int> lis;

	for (int i = 0; i < n; i++) {
		if (lis.empty() || lis.back() < nums[i]) {
			lis.push_back(nums[i]);
		}

		else {
			auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
			*it = nums[i];
		}
	}

	cout << lis.size();
}