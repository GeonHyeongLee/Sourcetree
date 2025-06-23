#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

// b가 a의 약수라면 b만큼이 최대공약수를 이룰 것이다.
long long int gcd(long long int a, long long int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main(void) {
	long long int a;
	long long int b;
	cin >> a >> b;


	long long int big_num;
	long long int small_num;

	if (a > b) {
		big_num = a;
		small_num = b;
	}
	else {
		big_num = b;
		small_num = a;
	}

	string res;

	long long int gcd_num = gcd(big_num, small_num);

	if (gcd_num == 1) {
		cout << 1 << endl;
	}
	else {
		for (long long int i = 0; i < gcd_num; i++) {
			res += '1';
		}

		cout << res << endl;
	}
}
