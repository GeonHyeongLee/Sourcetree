#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;

vector<string> types;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cin.ignore();
		unordered_map<string, int> clothes;

		for (int j = 0; j < num; j++) {
			string str;
			getline(cin, str);
			stringstream ss(str);

			string name, what;
			ss >> name >> what;
			clothes[what] += 1;
			types.push_back(what);
		}

		int answer = 1;

		for (auto& map : clothes) {
			answer *= (map.second+1);
		}


		cout << answer - 1 << "\n";
	}
}