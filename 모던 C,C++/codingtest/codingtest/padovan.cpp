//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int memo[100];
//
//
//int padovan(int memo[], int idx) {
//	if (memo[idx] != -1) {
//		return memo[idx];
//	}
//	if (idx <= 3) {
//		memo[idx] = 1;
//	}
//	else {
//		memo[idx] = padovan(memo, idx - 2) + padovan(memo, idx - 3);
//		cout << memo[idx];
//	}
//
//	return memo[idx];
//}
//
//int main() {
//
//	for (int i = 0; i < 100; i++) {
//		memo[i] = -1;
//	}
//
//	int res = padovan(memo, 10);
//	cout << res << endl;
//}