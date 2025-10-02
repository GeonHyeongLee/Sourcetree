#include <iostream>
#include <vector>
#include <algorithm>


#define MAX 1001

using namespace std;

int N;
vector<int> v;
int d[MAX];

int main(void) {
	cin >> N;

	for (int i = 0; i < MAX; i++) {
		d[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] < v[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	
	int max_num = 0;
	for (int i = 0; i < MAX; i++) {
		max_num = max(max_num, d[i]);
	}
	cout << max_num << "\n";
}