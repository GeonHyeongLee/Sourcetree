#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {
	cin >> n;

	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int> lis; // dp 배열

	vector<int> pos(n); // 산의 높이

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), num[i]); // 현재 숫자 위치

		int k = it - lis.begin(); // it를 int형으로 변환


		pos[i] = k + 1; // 실제 높이는 k + 1

		if (lis.empty() || lis.back() < num[i]) {
			lis.push_back(num[i]);
		}
		else {
			*it = num[i];
		}
	}

	int max_len = lis.size(); // 가장 긴 증가 부분 수열은 lis.size()
	int current_height = lis.size();  // 가장 높은 봉우리도 lis.size();
	
	vector<int> res; // 증가하는 부분 수열 저장할 결과 vector

	for (int i = n - 1; i >= 0; i--) { // 맨 뒷 길부터 시작한다
		if (pos[i] == current_height) { // 만약 지금 내려가야할 길이라면
			res.push_back(num[i]);
			current_height -= 1;
		}
	}

	reverse(res.begin(), res.end());

	cout << max_len << "\n";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}