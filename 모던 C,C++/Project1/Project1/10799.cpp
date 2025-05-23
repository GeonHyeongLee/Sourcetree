#include <iostream>
#include <stack>
#include <vector>
using namespace std;


// 1. �� �ε��� ������ ö���� �� ���� ���ִ����� �߿��ϴ�.
// 2. ���ִ� �������� () �߰� �� �� ������ŭ �������� ������
//	  count�� �� ������ �߰����ش�.

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string steel;

	cin >> steel;

	stack<int> st;

	int count = 0;

	// () (((()

	for (int i = 0; i < steel.size(); i++) {
		if (steel[i] == '(' && steel[i + 1] == ')') {
			count += st.size();
			i++; // �ߺ� ������ ���� �ǳʶٴ� ��
		}
		else if (steel[i] == '(') 
			st.push(i);
		else if (steel[i] == ')') {
			count++;
			st.pop();
		}
	}

	cout << count << endl;
}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string steel;
	cin >> steel;

	stack<int> st;

	int count = 0;

	for (int i = 0; i < steel.size(); i++) {
		if (steel[i] == '(' && steel[i + 1] == ')') {
			count += st.size();
			i++;
		}
		else if (steel[i] == '(') {
			st.push(i);
		}
		else if (steel[i] == ')') {
			st.pop();
			count++;
		}
	}
}