//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	// 
//	int a, b;
//
//	cin >> a >> b;
//
//	int new_a = 0;
//	int new_b = 0;
//	int count = 2;
//
//	while (a > 0) {
//		int digit = a % 10;
//
//		for (int i = 0; i < count; i++) {
//			digit *= 10;
//		}
//		new_a += digit;
//		a /= 10;
//		count -= 1;
//	}
//
//	int count_b = 2;
//
//	while (b > 0) {
//		int digit = b % 10;
//
//		for (int i = 0; i < count_b; i++) {
//			digit *= 10;
//		}
//		new_b += digit;
//		b /= 10;
//		count_b -= 1;
//	}
//
//	cout << max(new_a, new_b);
//}