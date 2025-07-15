#include <iostream>
#include <vector>

using namespace std;


int N, M;
vector<int> arr;
vector<int> result;

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
		result.push_back(arr[i]);
		back_tracking(count+1);
		result.pop_back();
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	back_tracking(0);

}