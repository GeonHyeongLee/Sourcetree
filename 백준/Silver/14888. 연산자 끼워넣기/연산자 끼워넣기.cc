#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 연산자 모음 0 : 더하기, 1 : 빼기, 2 : 곱하기, 3 : 나누기
vector<int> operators;

// 연산자에 따른 계산
long long int eval(vector<int>& nums, vector<int>& operators) {
	long long int result_num = nums[0];

	for (int i = 0; i < nums.size() - 1; i++) {
		if (operators[i] == 0) {
			result_num += nums[i + 1];
		}
		else if (operators[i] == 1) {
			result_num -= nums[i + 1];
		}
		else if (operators[i] == 2) {
			result_num *= nums[i + 1];
		}
		else if (operators[i] == 3) {
			result_num /= nums[i + 1];
		}
	}
	return result_num;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
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

	// next_permutation 사용하여서 전체 경우의 수 구하기
	// do-while문을 사용하여야 한다.
	long long max_num = -1000000001;
	long long min_num = 1000000001;

	do {
		long long int result_num = eval(nums, operators);

		max_num = max(max_num, result_num);
		min_num = min(min_num, result_num);

	} while (next_permutation(operators.begin(), operators.end()));
	

	cout << max_num << "\n";
	cout << min_num;
}