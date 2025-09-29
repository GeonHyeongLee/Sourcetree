#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int n; // 저장된 사이트 주소 수
int m; // 비밀번호 찾으려는 사이트 주소 수
string site;
string pass;

unordered_map<string, string> sites;
vector<string> result;

int main(void) {
	cin >> n >> m;
	
	// getline을 사용한다면 앞에서 cin >> n >> m으로 입력 받은 줄 바꿈 문자
	// 가 첫 번째 getline에 영향을 미쳐 비어있는 문자열에 들어간다
	// 그렇기에 cin.ignore()을 해줘야 한다.
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		string store;
		getline(cin, store);

		// ' '의 위치를 찾아서
		size_t pos = store.find(' ');

		// 공백 기준 앞은 site, 뒤는 비밀번호로 나눈다
		if (pos != string::npos) {
			site = store.substr(0, pos);
			pass = store.substr(pos + 1);
		}

		sites.insert({site, pass});
	}

	for (int i = 0; i < m; i++) {
		string password;
		getline(cin, password);

		if (sites.find(password) != sites.end()) {
			cout << sites[password] << "\n";
		}
	}
}