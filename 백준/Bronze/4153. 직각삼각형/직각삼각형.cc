#include <iostream>
#include <algorithm>

using namespace std;

bool ifright(int a, int b, int c) {
	if (a* a == b*b + c * c) {
		return true;
	}
	else if (b * b == a * a + c* c) {
		return true;
	}
	else if (c * c == a*a + b * b) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if (ifright(a, b, c)) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}
}