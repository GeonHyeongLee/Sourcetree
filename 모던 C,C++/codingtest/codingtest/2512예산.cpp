// vector에서 숫자를 지우고 싶으면
// vector<int> v라고 할 때
// v.erase(v.begin() + i) => i가 지우고 싶은 인덱스 넘버

#include <iostream>
#include <vector>

using namespace std;

bool Candiv(vector<int> arr, int sum) {

	int var = sum / (int)arr.size();
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < var) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int N;
	int sum;
	cin >> N;
	vector<int> num;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num.push_back(n);
	}
	cin >> sum;

	int sum_copy = sum;

	for (int i = 0; i < N; i++) {
		sum_copy -= num[i];
	}

	if (sum_copy > 0) {
		int max_num = 0;
		for (int i = 0; i < N; i++) {
			if (num[i] > max_num) {
				max_num = num[i];
			}
		}
		cout << max_num;
	}

	else {

		while (true) {
			if (Candiv(num, sum) == true) {
				break;
			}

			if (Candiv(num, sum) == false) {
				int vir = sum / num.size();
				for (int i = 0; i < num.size(); i++) {
					if (num[i] < vir) {
						sum -= num[i];
						num.erase(num.begin() + i);
					}
				}
			}
		}

		int result = sum / num.size();
		cout << result << endl;


	}

}