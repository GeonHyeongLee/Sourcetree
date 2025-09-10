#include <iostream>

using namespace std;

int a;
int b;

bool can_find = true;

int main(void) {
	cin >> a >> b;

	int cnt = 0;

	while (b > 0) {
		if (b == a) {
			break;
		}

		if (b > 10 && (b - 1) % 10 == 0) {
			b = (b - 1) / 10;
			cnt += 1;
		}
		else if (b % 2 == 0) {
			b /= 2;
			cnt += 1;
		}
		else {
			can_find = false;
			break;
		}
	}
	if (can_find == false) {
		cout << -1 << "\n";
	}
	else {
		cout << cnt + 1 << "\n";
	}
}