// 1. ù ��° ����� sort �� find�Լ��� ����ϴ� ���̴�.
// find �Լ��� ���ؼ��� �Ʒ��� �ڼ��� �������.

// vector���� find �Լ� 
// find() �Լ��� ���ڿ����� Ư�� ���ڿ��� ã�� �Լ�
// size_t find(const string& str, size_t pos = 0) const;
// Ư�� ���ڿ��� ã���� �ش� �ε����� �� �� ��ġ�� �ε����� ��ȯ�Ѵ�. �׷��Ƿ� find(phone_book[i].find(phone_book[i-1]) == 0) �̶�� �� �տ� phone_book[i-1]�� �ִٴ� �Ͱ� �����ϴٴ� ���̴�.

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

// 2��° ����� �ؽ����� unordered_map�� ����Ѵ�
// // �� ����� �� ������� �ؽ� ������ �ɸ´� Ǯ�� ����̶�� ������ ���.
// unordered_map�� ����ؼ� 119, 97674223 �� ��� ��ȭ��ȣ�� ���� 1�� �ο��Ѵ�.
// ���� substr(0, j+1)�� ���ؼ� �ε��� j������ ���ڿ��� �߶� �߸��� map���� 1�� �ο��Ǿ��ִٸ� return false�� �ϴ� ���

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {

    // 1. HashMap�� �����.
    unordered_map<string, int> map;

    for (int i = 0; i < phone_book.size(); i++) {
        map[phone_book[i]] = 1;
    }

    // 2. ��� ��ȭ��ȣ�� substring�� HashMap�� �����ϴ��� Ȯ���Ѵ�.

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