// 10진수를 2진수로 변환할 시 11001의 형태는 1 * 2 + 0 * 2^1 + 0 * 2^2 + 1 * 2^3 + 1 * 2^4일 것이다. 
// 이를 식으로 나타내면 num = (num*2) + (binary[i] - '0')이다.
// 계산을 할 때에는 왼쪽부터 읽어서 올라나간다.
// 왼쪽이 제일 큰 값인데 왜 왼쪽부터 읽을까?
// 그건 왼쪽이 가장 큰 값이기 때문이다. num은 계속해서 2배씩 증가하기 때문에
// 왼쪽에서 시작해야지 결과적으로 가장 많이 2가 곱해질 것이라는 것을 알 수 있다.

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