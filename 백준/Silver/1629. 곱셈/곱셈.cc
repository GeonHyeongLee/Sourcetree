#include <iostream>

using namespace std;

long long int a, b, c;

long long int modular(int B) {
	if (B == 1) {
		return a % c;
	}

	long long int res = modular(B / 2) % c;

	if (B % 2 == 0) {
		return res * res % c;
	}
	else {
		return ((res * res % c) * (a % c)) % c;
	}
}

int main(void) {
	cin >> a >> b >> c;

	cout << modular(b);
}