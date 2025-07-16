#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num_arr;
vector<int> result;

void print_num(void) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void find_permutation(int cur, int count) {
	if (count == m) {
		print_num();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (num_arr[i] >= cur) {
			cur = num_arr[i];
			result.push_back(num_arr[i]);
			find_permutation(cur, count + 1);
			result.pop_back();
		}
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		num_arr.push_back(i);
	}

	find_permutation(1, 0);
}