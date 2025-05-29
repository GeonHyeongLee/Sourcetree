//// bottom-up방식
//// 아래서부터 반복문을 통해 올라오는 
//// tabulation 방식을 사용
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//
//using namespace std;
//
//int main() {
//	vector<int> dp = { 0 };
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		dp[i] = 0;
//	}
//
//	dp[1] = 1;
//	dp[2] = 1;
//
//	for (int i = 4; i <= n; i++) {
//		dp[i] = dp[i - 3] + dp[i - 2];
//	}
//
//	dp[n];
//}