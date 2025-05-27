#include <iostream>

using namespace std;

int N;

int value = 0;


// 이 방식으로 깔끔하게 처리하자
int all_sum(int n) {
    if (n == 1) {
        return 1;
    }
    return all_sum(n - 1) + n;
}

// 이런식으로 하면 너무 메모리를 많이 잡아먹게 된다.
int value = 0;
int all_sum(int n) {
    if (n == 0) {
        return value;
    }
    value += n;
    all_sum(n - 1);
}



int main() {
    cin >> N;
    int res = all_sum(N);
    cout << res;
    return 0;
}


