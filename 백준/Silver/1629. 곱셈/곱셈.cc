#include <iostream>

using namespace std;

long long int A, B, C;

// 지수 법칙 : a^(n+m) = a^n * a^m
// A8 = A4 * A4 
// A9 = A * A4 * A4
// 모듈러 법칙 : (a * b) % c = ((a % c) * (b % c)) % c

// f함수는 Ay(modC)를 계산하는 함수이다
// y == 1이면 AmodC를 반환한다

// 현재 계산하려는 지수 y를 반으로 나눈 y/2에 대해 함수를 재호출한다
// 만약 y가 짝수이면 Ay = A(y/2) * A(y/2)
// 만약 y가 홀수이면 Ay = A(y/2) * A(y/2) * A

// B= 11이면 
// f(11) 호출
// f(11)은 f(5) * f(5) * 1
// 즉 f(5) 필요함
// f(5)는 f(2)가 필요함
// f(2)는 f(1)이 필요함
// f(1)은? A % C의 값임
// 그러면 이제 타고 올라가서
// f(2) = f(1) * f(1) % C
// f(5) = f(2) * f(2) * f(1)
// f(11) = f(5) * f(5) * f(1)


long long int modular(int y) {
	if (y == 1) {
		return A % C;
	}

	long long int result = modular(y / 2) % C;

	if (y % 2 == 0) {
		return result * result % C;
	}
	else {
		return ((result * result % C) * (A % C)) % C;
	}


}


int main(void)
{
	cin >> A >> B >> C;

	cout << modular(B) << "\n";

}