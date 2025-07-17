#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num_arr;
vector<int> result;
bool used[1001];

void print_num(void) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void back_tracking(int count) {
	
	if (count == M) {
		print_num();
		return;
	}

	for (int i = 0; i < N; i++) {

		if (used[i])
			continue;

		used[i] = true;
		result.push_back(num_arr[i]);
		back_tracking(count + 1);
		result.pop_back();

		used[i] = false;
	}

}


int main(void) {
	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		num_arr.push_back(num);
	}

	sort(num_arr.begin(), num_arr.end());

	back_tracking(0);

}