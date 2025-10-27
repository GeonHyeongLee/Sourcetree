#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// p1, p2, p3, p4, ..... , pn


int main(void) {

	int n;

	while (cin >> n) {
		
		vector<int> num(n + 1);

		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		vector<int> lis;

		for (int i = 0; i < n; i++) {
			if (lis.empty() || num[i] > lis.back()) {
				lis.push_back(num[i]);
			}
			else {
				auto it = lower_bound(lis.begin(), lis.end(), num[i]);
				*it = num[i];
			}
		}

		cout << lis.size() << "\n";
	}
}