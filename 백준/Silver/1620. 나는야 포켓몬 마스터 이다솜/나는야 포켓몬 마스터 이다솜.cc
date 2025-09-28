#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int n; // 포켓몬 개수
int m; // 맞춰야 하는 문제

unordered_map<string, int> un_map; // unordered_map은 key->value 한 방향 매핑만 가능
unordered_map<int, string> un_map2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		un_map.insert({ s,i });
		un_map2.insert({ i,s });
	}

	for (int i = 0; i < m; i++) {
		string question;
		cin >> question;

		if (question[0] >= 'A' && question[0] <= 'Z') {
			cout << un_map[question] + 1<< "\n";
		}
		else {
			int index_num = stoi(question);
			cout << un_map2[index_num-1] << "\n";
		}
	}
}