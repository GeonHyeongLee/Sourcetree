#include <iostream>

#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	queue<int> q;

	int num;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				num = q.front();
				cout << num << endl;
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "empty") {
			if (q.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				num = q.front();
				cout << num << endl;
			}
		}
		else if (s == "back") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				num = q.back();
				cout << num << endl;
			}
		}
	}
}