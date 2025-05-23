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
//	while (true) {
//		string input;
//		getline(cin, input);
//
//		stack<char> stk;
//		bool empty = 0;
//
//
//		if (input == ".") {
//			break;
//		}
//
//		for (int i = 0; i < input.length(); i++) {
//			char c = input[i];
//			if ((c == '[') || (c == '(')) {
//				stk.push(c);
//			}
//			else if (c == ']') {
//				if (!stk.empty() && stk.top() == '[') {
//					stk.pop();
//				}
//				else {
//					empty = 1;
//					break;
//				}
//			}
//			else if (c == ')') {
//				if (!stk.empty() && stk.top() == '(') {
//					stk.pop();
//				}
//				else {
//					empty = 1;
//					break;
//				}
//			}
//		}
//
//		if (empty == 0 && stk.empty()) {
//			cout << "yes" << endl;
//		}
//		else {
//			cout << "no" << endl;
//		}
//	}
//
//}