//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int n;
//	cin >> n;
//
//	int count = 0;
//
//	for (int i = 0; i < n; i++) {
//		string input;
//		cin >> input;
//		stack<char> stk;
//
//		for (int j = 0; j < input.size(); j++) {
//			if (stk.empty()) {
//				stk.push(input[j]);
//			}
//
//			else {
//				if (stk.top() != input[j]) {
//					stk.push(input[j]);
//				}
//				else {
//					stk.pop();
//				}
//			}
//
//			
//		}
//
//		if (stk.empty()) {
//			count += 1;
//		}
//	}
//
//	cout << count;
//}