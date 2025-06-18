//진짜 제목 그대로 아름다운 수를 만드는 코드이다.
//
//bool isBeautiful을 만드는 과정이 정말 괜찮은 방법인 것 같다.
//for (int i = 0; i < n; i += arr[i])를 해줌으로써 자기가 걸리는 순간부터 뒤까지를 세주는 방법이 
//기가 막힌다.
//
//처음에는 아름다운 수를 바로 만들어보려했지만, 그 방법보다는 순열을 만들듯이 우선 만들어질 수 있는 모든 수를 
//그 과정에서 판별식을 적용해서 맞으면 늘려가는 방법이 훨씬 쉽다.
//


// 한 번에 아름다운 수를 만든다? xxxx
// 1-4 사이의 숫자로만 이루어진 모든 숫자를 만들어낸 뒤 그 중 아름다운 수의 수를 센다 O


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
