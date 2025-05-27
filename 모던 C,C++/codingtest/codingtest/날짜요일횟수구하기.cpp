#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m1, m2, d1, d2;
string A;

int main() {

    vector<int> month = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    vector<string> week = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };

    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    int sum2 = d2;

    for (int i = 0; i < m2; i++) {
        sum2 += month[i];
    }

    int sum1 = d1;

    for (int i = 0; i < m1; i++) {
        sum1 += month[i];
    }

    int day = sum2 - sum1 + 1;

    int res;

    int offset = 0;

    for (int i = 0; i < week.size(); i++) {

    }
    if (A == week[1]) {
        day -= 1;
    }
    else if (A == week[2]) {
        day -= 2;
    }
    else if (A == week[3]) {
        day -= 3;
    }
    else if (A == week[4]) {
        day -= 4;
    }
    else if (A == week[5]) {
        day -= 5;
    }
    else if (A == week[6]) {
        day -= 6;
    }

    res = (day + 6) / 7;


    cout << res;
    return 0;
}