#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 11

using namespace std;

int n, k;

vector<int> arr;

int main(void) {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	reverse(arr.begin(), arr.end());

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (k >= arr[i]) {
			cnt += (k / arr[i]);
			k %= arr[i];
		}
	}


	cout << cnt << "\n";
}