// 10������ 2������ ��ȯ�� �� 11001�� ���´� 1 * 2 + 0 * 2^1 + 0 * 2^2 + 1 * 2^3 + 1 * 2^4�� ���̴�. 
// �̸� ������ ��Ÿ���� num = (num*2) + (binary[i] - '0')�̴�.
// ����� �� ������ ���ʺ��� �о �ö󳪰���.
// ������ ���� ū ���ε� �� ���ʺ��� ������?
// �װ� ������ ���� ū ���̱� �����̴�. num�� ����ؼ� 2�辿 �����ϱ� ������
// ���ʿ��� �����ؾ��� ��������� ���� ���� 2�� ������ ���̶�� ���� �� �� �ִ�.

#include <iostream>
#include <string>
#include <cstring>


// int -> char
// char num = num + '0';

// char -> int
// int num = num - '0';


using namespace std;

char binary[9];

int main() {
    cin >> binary;

    int num = 0;

    for (int i = 0; i < strlen(binary); i++) {
        num = num * 2 + (binary[i] - '0');
    }
    cout << num;
    return 0;
}