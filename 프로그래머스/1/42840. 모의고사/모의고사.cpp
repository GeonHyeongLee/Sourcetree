// 1,2,3,4,5 ...
// 2,1,2,3,2,4,2,5
// 3,3,1,1,2,2,4,4,5,5


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    int cnt_1 = 0;
    int cnt_2 = 0;
    int cnt_3 = 0;
    int math1[5] = {1,2,3,4,5};
    int math2[8] = {2,1,2,3,2,4,2,5};
    int math3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    for (int i = 0; i < answers.size(); i++) {
        // 1 2 3 4 5 
        if (math1[i%5] == answers[i]) {
            cnt_1 += 1;
        }
        if (math2[i%8] == answers[i]) {
            cnt_2 += 1;
        }
        if (math3[i%10] == answers[i]) {
            cnt_3 += 1;
        }
    }
    
    int max_num = max({cnt_1, cnt_2, cnt_3});
    
    
    vector<int> answer;
    
    if (cnt_1 == max_num) {
        answer.push_back(1);
    }
    if (cnt_2 == max_num) {
        answer.push_back(2);
    }
    if (cnt_3 == max_num) {
        answer.push_back(3);
    }
    
    return answer;

}