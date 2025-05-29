//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int memo[100];
//
//int fibo(int n) {
//	if (memo[n] != -1) {
//		return n;
//	}
//	if (n <= 2) {
//		memo[n] = 1;
//	}
//	else {
//		n = fibo(n - 1) + fibo(n - 2);
//	}
//
//	return n;
//}
//
//int main() {
//	for (int i = 0; i < 100; i++) {
//		memo[i] = -1;
//	}
//
//	int res = fibo(6);
//	cout << res << endl;
//}