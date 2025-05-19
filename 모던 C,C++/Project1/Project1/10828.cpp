// C++������ ����

// 1. stack <������Ÿ��> �̸�; ����
// 2. ���ÿ� element(����) �߰�; s.push(element);
// 3. ������ ���Ҹ� �����Ѵ�; s.pop(); ���� �� ���� ����
// 4. s.size(); ������ ������ ��ȯ
// 5. s.empty(); ������ ����ִ��� Ȯ��
// 6. s.top(); ������ ���� ���� �ִ� ���� ��ȯ

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