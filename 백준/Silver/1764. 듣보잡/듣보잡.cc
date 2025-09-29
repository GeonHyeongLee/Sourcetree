#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
int M;

// map<key,value> => key 값 기준으로 sorting 되어있음
// unordered_map<key, value> => map은 정렬됨, unordered_map은 정렬되지 않은 데이터 구조
// unordered_map.find(key) => key가 있는지를 찾을 수 있음
// 찾는 방법은 unordered_map.find(key) != unordered_map.end(); 
// iterator 기준으로 나오기에 이렇게 하면 끝까지 가기 전에 나왔다는 말이다.
unordered_map<string , int> see_hear;
vector<string> result;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		string hear;
		cin >> hear;
		see_hear.insert({ hear,i });
	}

	for (int i = 0; i < M; i++) {
		string see;
		cin >> see;
		if (see_hear.find(see) != see_hear.end()) {
			cnt += 1;
			result.push_back(see);
		}
		else {
			continue;
		}
	}
	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0;i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}