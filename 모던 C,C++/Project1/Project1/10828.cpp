// C++에서의 스택

// 1. stack <데이터타입> 이름; 선언
// 2. 스택에 element(원소) 추가; s.push(element);
// 3. 스택의 원소를 삭제한다; s.pop(); 가장 위 원소 삭제
// 4. s.size(); 스택의 사이즈 반환
// 5. s.empty(); 스택이 비어있는지 확인
// 6. s.top(); 스택의 가장 위에 있는 원소 반환

#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;
	int n;
	string command;

	int num;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;

		if (command == "push") {
			cin >> num;
			s.push(num);
		}
		else if (command == "pop") {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				num = s.top();
				cout << num << endl;
				s.pop();
			}
		}
		else if (command == "size") {
			cout << s.size() << endl;
		}
		else if (command == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (command == "top") {
			int result;
			result = s.top();
			cout << result << endl;
		}
	}


}