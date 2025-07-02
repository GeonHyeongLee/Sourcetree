//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		int N;
//		cin >> N;
//		vector<int> arr;
//
//		int num;
//		for (int i = 0; i < N; i++) {
//			cin >> num;
//			arr.push_back(num);
//		}
//
//		int total = 0;
//		for (int i = 1; i < arr.size(); i++) {
//			total += abs(arr[i] - arr[i-1]);
//		}
//
//		int max_reduction = 0;
//		for (int i = 1; i < N - 1; i++) {
//			int normal = abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i]);
//			int skip = abs(arr[i + 1] - arr[i - 1]);
//			int reduction = normal - skip;
//			if (reduction > max_reduction) {
//				max_reduction = reduction;
//			}
//		}
//
//		cout << total - max_reduction << "\n";
//	}
//}