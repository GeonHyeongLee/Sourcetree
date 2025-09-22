#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int c;
vector<int> house;

bool can_go(int mid) {

	int now = house[0];
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (house[i] >= now + mid) {
			now = house[i];
			cnt += 1;
			if (cnt >= c) {
				return true;
			}
		}
	}
	return false;
}
int main(void) {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		house.push_back(x);
	}
	
	sort(house.begin(), house.end());

	int head = house.front();
	int tail = house.back();

	int closest = 0;
	int farthest = tail - head;

	int result = 0;
	while (closest <= farthest) {
		int middle = (closest + farthest) / 2;

		if (can_go(middle)) {
			result = middle;
			closest = middle + 1;
		}
		else {
			farthest = middle - 1;
		}
	}

	cout << result;
}