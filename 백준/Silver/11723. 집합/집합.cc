#include <iostream>

using namespace std;

int m;
int s[21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++) {
		string to_do;
		int num;

		cin >> to_do;

		if (to_do == "add") {
			cin >> num;
			s[num] = 1;
		}
		else if (to_do == "remove") {
			cin >> num;
			s[num] = 0;
		}
		else if (to_do == "check") {
			cin >> num;
			if (s[num] == 1) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (to_do == "toggle") {
			cin >> num;
			if (s[num] == 1) {
				s[num] = 0;
			}
			else {
				s[num] = 1;
			}
		}
		else if (to_do == "all") {
			for (int j = 1; j <= 20; j++) {
				s[j] = 1;
			}
		}
		else if (to_do == "empty") {
			for (int j = 1; j <= 20; j++) {
				s[j] = 0;
			}
		}
	}
}