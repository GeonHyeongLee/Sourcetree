// 지폐 접을 때 길이가 긴 쪽을 반으로 접는다
// 접기 전 홀수였다면 접은 후 소수점 버림
// 접힌 지폐 그대로 또는 90도 돌려 넣을 수 있으면 그만 접음
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// wallet에 지갑의 가로, 세로 크기 담김
// bill에 지폐 가로,세로 크기 담김
int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while (1) {
        
        if ((bill[0] <= wallet[0] && bill[1] <= wallet[1]) || (bill[1] <= wallet[0] && bill[0] <= wallet[1])) {
            break;
        }
        int bigger = max(bill[0], bill[1]);
        
        if (bigger == bill[0]) {
            bill[0] /= 2;
            answer += 1;
            
        }
        else {
            bill[1] /= 2;
            answer += 1;
        }
    }
    
    return answer;
}