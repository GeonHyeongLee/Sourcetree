#include <iostream>
#include <stack>
#include <vector>
using namespace std;


// 1. 각 인덱스 지점에 철근이 몇 개가 모여있는지가 중요하다.
// 2. 모여있는 지점에서 () 발견 시 그 개수만큼 나눠지기 때문에
//	  count에 그 개수를 추가해준다.

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
			i++; // 중복 방지를 위해 건너뛰는 것
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