#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 200001
#define MAX 200001
vector<int> house;
int n;
int c;
int used_router = 0;

bool can_use(int middle) {
	used_router = 1;
	int now = house[0];

	for (int i = 1; i < n; i++) {
		if (house[i] >= now + middle) {
			now = house[i];
			used_router += 1;
			if (used_router >= c) {
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

	int closest = 1;
	int farthest = tail - head;

	int answer = 0;
	while (closest <= farthest) {
		int middle = (closest + farthest) / 2;

		if (can_use(middle)) {
			answer = middle;
			closest = middle + 1;
		}
		else {
			farthest = middle - 1;
		}
	}

	cout << answer;
}


