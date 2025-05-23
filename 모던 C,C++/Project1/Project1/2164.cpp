//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//
//	// 1 2 3 4 5 6
//	// 3 4 5 6 2
//	// 5 6 2 4
//	// 2 4 6
//	// 6 4
//	// 4
//
//	// 1 -> 2 -> 3 -> 4 -> 5 -> 6 ==. [6,5,4,3,2,1]
//	// q.pop();
//	// q.front() = q.back();
//
//	queue<int> q;
//
//	for (int i = 1; i <= n; i++) {
//		q.push(i);
//	}
//
//	while (q.size() > 1) {
//		q.pop();
//
//		int tmp = q.front();
//		q.push(tmp);
//		q.pop();
//	}
//
//	
//	cout << q.front() << endl;
//
//	return 0;
//}