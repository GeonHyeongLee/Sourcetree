// 최초 풀이

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    bool same = false;
    string result;
    for (int i = 0; i < completion.size(); i++) {
        for (int j = 0; j < participant.size(); j++) {
            if (completion[i] == participant[j]) {
                same = true;

                participant.erase(participant.begin() + j);
                break;
            }
        }
    }

    result = participant[0];
    return result;
}

// 정렬하여 풀기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }

    return participant[participant.size() - 1];
}

// unordered_map 사용하여 풀기


#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> map;

    for (const string& p : participant) {
        map[p]++;
    }

    for (const string& c : completion) {
        map[c]--;
    }

    for (const string& p : participant) {
        if (map[p] > 0) {
            return p;
        }
    }

}