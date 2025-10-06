#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int n;

int main(void) {
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cin.ignore();
		unordered_map<string, int> clothes;
		for (int j = 0; j < num; j++) {
			string cloth;
			getline(cin, cloth);

			stringstream ss(cloth);
			string name, type;
			ss >> name >> type;

			//cout << name << type << "\n";

			clothes[type] += 1;
		}
		int result = 1;

		for (auto& map : clothes) {
			result *= (map.second + 1);
		}

		cout << result - 1 << "\n";
	}
}