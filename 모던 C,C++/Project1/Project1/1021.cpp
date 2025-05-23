//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main() {
//	int n;
//	int m;
//	cin >> n >> m;
//
//	deque<int> dq;
//
//	for (int i = 1; i <= n; i++) {
//		dq.push_back(i);
//	}
//
//	int target;
//	int sum = 0;
//	for (int i = 0; i < m; i++) {
//		cin >> target;
//		if (dq.front() == target) {
//			dq.pop_front();
//		}
//		else {
//			int left_count = 0;
//			int right_count = 0;
//
//			deque<int> dq_copy = dq;
//
//			while (dq_copy.front() != target) {
//				dq_copy.push_back(dq_copy.front());
//				dq_copy.pop_front();
//				left_count += 1;
//			}
//
//			dq_copy = dq;
//
//			while (dq_copy.front() != target) {
//				dq_copy.push_front(dq_copy.back());
//				dq_copy.pop_back();
//				right_count += 1;
//			}
//
//			sum += min(left_count, right_count);
//
//			if (left_count > right_count) {
//				while (dq.front() != target) {
//					dq.push_front(dq.back());
//					dq.pop_back();
//					right_count += 1;
//				}
//			}
//			else {
//				while (dq.front() != target) {
//					dq.push_back(dq.front());
//					dq.pop_front();
//					left_count += 1;
//				}
//			}
//			dq.pop_front();
//		}
//	}
//
//	cout << sum << endl;
//
//	return 0;
//}