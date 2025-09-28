#include <iostream>

using namespace std;


int n;

int main(void) {
	cin >> n;

	// 티셔츠는 n 명의 참가자에게 나누어주고 남아도 되지만 부족해서는 안된다
	int s, m, l, xl, xxl, xxxl;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;

	// 펜은 남거나 부족해서는 안되고 정확히 참가자 수만큼 준비되어야 한다
	int t, p; // t는 티셔츠 묶음 수, p는 펜 묶음 수
	cin >> t >> p;

	int sum_t = 0;
	if (s % t != 0) {
		sum_t += (s / t + 1);
	}
	else {
		sum_t += (s / t);
	}
	//cout << sum_t << "\n";

	if (m % t != 0) {
		sum_t += (m / t + 1);
	}
	else {
		sum_t += (m / t);
	}

	if (l % t != 0) {
		sum_t += (l / t + 1);
	}
	else {
		sum_t += (l / t);
	}

	if (xl % t != 0) {
		sum_t += (xl / t + 1);
	}
	else {
		sum_t += (xl / t);
	}

	if (xxl % t != 0) {
		sum_t += (xxl / t + 1);
	}
	else {
		sum_t += (xxl / t);
	}

	if (xxxl % t != 0) {
		sum_t += (xxxl / t + 1);
	}
	else {
		sum_t += (xxxl / t);
	}

	cout << sum_t << "\n";

	cout << (n / p) << " " << (n % p) << "\n";
}