#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

int N, M;

vector<int> num_arr;
vector<int> result;


void print_num(void) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void back_tracking(int cur , int count) {
	if (count == M) {
		print_num();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (num_arr[i] >= cur) {
			cur = num_arr[i];
			result.push_back(num_arr[i]);
			back_tracking(cur + 1, count + 1);
			result.pop_back();
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		num_arr.push_back(i);
	}

	back_tracking(1, 0);

}