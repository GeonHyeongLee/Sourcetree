#include <iostream>
#include <vector>
using namespace std;


// vector<pair<int,int>> map = {{a,b},{c,d},{e,f}} 이런식으로 입력을 받는다면 꺼낼 때는 map[0].first = a, map[0].second = b => 이런식으로 꺼낼 수 있다.
int Y, M, D;

bool leap_year(int Y) {
    if (Y % 4 == 0) {
        if (Y % 100 == 0) {
            if (Y % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

void weather(int y, int m, int d) {
    vector<pair<int, int>> month_day = { {4,31},{6,31},{9,31},{11,31} };

    bool true_false = true;

    for (int i = 0; i < month_day.size(); i++) {
        if (m == month_day[i].first && d == month_day[i].second) {
            true_false = false;
        }
    }

    if (leap_year(y)) {
        if (m == 2 && d >= 30) {
            true_false = false;
        }
    }
    else if (!leap_year(y)) {
        if (m == 2 && d >= 29) {
            true_false = false;
        }
    }

    if (true_false == true) {
        if (m >= 3 && m <= 5) {
            cout << "Spring";
        }
        else if (m >= 6 && m <= 8) {
            cout << "Summer";
        }
        else if (m >= 9 && m <= 11) {
            cout << "Fall";
        }
        else {
            cout << "Winter";
        }
    }

    else {
        cout << -1;
    }
}

int main() {
    cin >> Y >> M >> D;

    weather(Y, M, D);
    // Please write your code here.

    return 0;
}