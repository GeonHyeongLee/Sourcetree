#include <iostream>
#include <vector>


using namespace std;

int N;
int M;

vector<int> v;
vector<int> res;

void print_res() {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
}

void back_tracking(int cur_num, int cur_cnt, int len) {
	if (cur_cnt == M) {
		print_res();
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= cur_num) {
			cur_num = v[i];
			res.push_back(cur_num);
			back_tracking(v[i]+1, cur_cnt + 1, len);
			res.pop_back();
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	back_tracking(v[0], 0, M);
	
}