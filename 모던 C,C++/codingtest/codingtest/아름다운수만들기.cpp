//��¥ ���� �״�� �Ƹ��ٿ� ���� ����� �ڵ��̴�.
//
//bool isBeautiful�� ����� ������ ���� ������ ����� �� ����.
//for (int i = 0; i < n; i += arr[i])�� �������ν� �ڱⰡ �ɸ��� �������� �ڱ����� ���ִ� ����� 
//�Ⱑ ������.
//
//ó������ �Ƹ��ٿ� ���� �ٷ� ������������, �� ������ٴ� ������ ������� �켱 ������� �� �ִ� ��� ���� 
//�� �������� �Ǻ����� �����ؼ� ������ �÷����� ����� �ξ� ����.
//


// �� ���� �Ƹ��ٿ� ���� �����? xxxx
// 1-4 ������ ���ڷθ� �̷���� ��� ���ڸ� ���� �� �� �� �Ƹ��ٿ� ���� ���� ���� O


#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int count = 0;

void print_backtracking() {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
    cout << endl;
}


bool IsBeautiful() {
    for (int i = 0; i < n; i += arr[i]) {
        if (i + arr[i] - 1 >= n) {
            return false;
        }
        for (int j = i; j < i + arr[i]; j++) {
            if (arr[j] != arr[i]) {
                return false;
            }
        }
    }
    return true;
}


void make_backtracking(int num) {
    if (num == n) {
        if (IsBeautiful()) {
            count++;
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        arr.push_back(i);
        make_backtracking(num + 1);
        arr.pop_back();
    }
}



int main() {
    cin >> n;

    make_backtracking(0);

    cout << count;

    return 0;
}
