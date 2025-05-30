#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int bin[100] = { 0 };
	int cnt = 0;

	while (true) {
		if (n < 2) {
			bin[cnt++] = n;
			break;
		}

		bin[cnt++] = n % 2;
		n /= 2;
	}

	for (int i = cnt - 1; i >= 0; i--) {
		cout << bin[i];
	}
}