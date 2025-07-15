#include <iostream>
#include <vector>

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

void find_permutation(int count) {
	
	if (count == M) {
		print_num();
		return; 
	}


	for (int i = 0; i < N; i++) {

		if (used[i])
			continue;

		used[i] = true;
		result.push_back(num_arr[i]);

		find_permutation(count + 1);
		result.pop_back();

		used[i] = false;
	}
}
int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		num_arr.push_back(i);
	}

	find_permutation(0);

}