#include <iostream>
#include <vector>
#include <algorithm>
// num_arr vector�� ������ .push_back()�� �ִ� �� ��������!!
// ��ͷ� ���� �� �ٷ� �׳� cur�ڸ��� num_arr[i]�ִ°Ծƴ϶�
// cur= num_arr[i], cur �ִ°Ը´�...

// �߿��Ѱ� ��Ʈ��ŷ�� �ٽ���
// .push_back()  ��� .pop_back()�� ���ִ� ���̴�.

using namespace std;

int N, M;

vector<int> num_arr;
vector<int> result;

void printnum(void) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void find_permutation(int cur, int count) {

	if (count == M) {
		printnum();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (num_arr[i] >= cur) {
			cur = num_arr[i];
			result.push_back(cur);
			find_permutation(cur, count + 1);
			result.pop_back();
		}
	}
}

int main(void) {
	cin >> N >> M;
	
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num_arr.push_back(a);
	}

	sort(num_arr.begin(), num_arr.end());

	find_permutation(num_arr[0], 0);

	return 0;
}