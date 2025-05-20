// 1. 첫 번째 방법은 sort 후 find함수를 사용하는 것이다.
// find 함수에 대해서는 아래에 자세히 적어놨다.

// vector에서 find 함수 
// find() 함수는 문자열에서 특정 문자열을 찾는 함수
// size_t find(const string& str, size_t pos = 0) const;
// 특정 문자열을 찾으면 해당 인덱스의 맨 앞 위치의 인덱스를 반환한다. 그러므로 find(phone_book[i].find(phone_book[i-1]) == 0) 이라면 맨 앞에 phone_book[i-1]이 있다는 것과 동일하다는 것이다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); i++) {
        if (phone_book[i].find(phone_book[i - 1]) == 0) {
            return false;
        }
    }
    return true;
}

// 2번째 방법은 해쉬맵인 unordered_map을 사용한다
// // 이 방법이 더 어렵지만 해쉬 문제에 걸맞는 풀이 방법이라고 생각이 든다.
// unordered_map을 사용해서 119, 97674223 등 모든 전화번호에 대해 1을 부여한다.
// 이후 substr(0, j+1)을 통해서 인덱스 j까지로 문자열을 잘라서 잘린게 map에서 1이 부여되어있다면 return false를 하는 방식

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {

    // 1. HashMap을 만든다.
    unordered_map<string, int> map;

    for (int i = 0; i < phone_book.size(); i++) {
        map[phone_book[i]] = 1;
    }

    // 2. 모든 전화번호의 substring이 HashMap에 존재하는지 확인한다.

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].size() - 1; j++) {
            string phone_number = phone_book[i].substr(0, j + 1);

            if (map[phone_number]) {
                return false;
            }
        }
    }

    return true;

}