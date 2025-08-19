#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	int add;
	int minus;
	int mul;
	int div;

	cin >> add >> minus >> mul >> div;

	vector<int> operators;

	for (int i = 0; i < add; i++) {
		operators.push_back(0);
	}
	for (int i = 0; i < minus; i++) {
		operators.push_back(1);
	}
	for (int i = 0; i < mul; i++) {
		operators.push_back(2);
	}
	for (int i = 0; i < div; i++) {
		operators.push_back(3);
	}

	sort(operators.begin(), operators.end());

	long long int max_num = -1000000001;
	long long int min_num = 1000000001;

	do {
		long long int result = nums[0];

		for (int i = 0; i < n - 1; i++) {
			if (operators[i] == 0) {
				result += nums[i + 1];
			}
			else if (operators[i] == 1) {
				result -= nums[i + 1];
			}
			else if (operators[i] == 2) {
				result *= nums[i + 1];
			}
			else if (operators[i] == 3) {
				result /= nums[i + 1];
			}
		}

		max_num = max(max_num, result);
		min_num = min(min_num, result);

	} while (next_permutation(operators.begin(), operators.end()));

	cout << max_num << "\n" << min_num << "\n";
}