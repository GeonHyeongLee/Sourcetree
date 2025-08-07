#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int real_max = 0;
    for (int i = 0; i < sizes.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (sizes[i][j] > real_max) {
                real_max = sizes[i][j];
            }
        }
    }
    
    int second_max = 0;
    
    vector<int> smaller;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] >= sizes[i][1]) {
            smaller.push_back(sizes[i][1]);
        }
        else {
            smaller.push_back(sizes[i][0]);
        }
    }
    
    for (int i = 0; i < smaller.size(); i++) {
        if (smaller[i] > second_max) {
            second_max = smaller[i];
        }
    }
    
    return real_max * second_max;
}