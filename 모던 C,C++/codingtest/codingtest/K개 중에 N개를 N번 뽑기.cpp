#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> selected_nums;

void printpermutation() {
    for (int i = 0; i < selected_nums.size(); i++) {
        cout << selected_nums[i] << " ";
    }
    cout << "\n";
}

void findpermutation(int cnt) {
    if (cnt == N) {
        printpermutation();
        return;
    }

    for (int i = 1; i <= K; i++) {
        selected_nums.push_back(i);
        findpermutation(cnt + 1);
        selected_nums.pop_back();
    }
}



int main() {
    cin >> K >> N;

    findpermutation(0);

    return 0;
}
