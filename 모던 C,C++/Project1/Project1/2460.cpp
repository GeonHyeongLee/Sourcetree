//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	vector<vector<int>> v(10, vector<int>(2));
//
//	for (int i = 0; i < 10; i++) {
//		cin >> v[i][0] >> v[i][1];
//	}
//
//	for (int i = 1; i < 10; i++) {
//		v[i][1] += v[i - 1][1];
//		v[i][1] -= v[i][0];
//	}
//
//	int max_num = 0;
//	for (int i = 0; i < 10; i++) {
//		if (v[i][1] > max_num) {
//			max_num = v[i][1];
//		}
//	}
//
//	cout << max_num;
//}