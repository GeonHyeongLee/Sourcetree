#include <iostream>
#include <vector>

#define MAX 1000001
using namespace std;

int n; 
int m;


int find_root(vector<int>& union_find, int x) {
	if (union_find[x] == x) {
		return x;
	}

	return union_find[x] = find_root(union_find, union_find[x]);
}

bool is_same_union(vector<int>& union_find, int x, int y) {
	int rootx = find_root(union_find, x);
	int rooty = find_root(union_find, y);

	if (rootx == rooty) {
		return true;
	}
	else {
		return false;
	}
}

void union_set(vector<int>& union_find, int x, int y) {
	int rootx = find_root(union_find, x);
	int rooty = find_root(union_find, y);

	if (rootx != rooty) {
		union_find[rooty] = rootx;
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> union_find(n+1, 0);


	for (int i = 1; i <= n; i++) {
		union_find[i] = i;
	}



	for (int i = 0; i < m; i++) {
		int order, a, b;
		cin >> order >> a >> b;

		if (order == 1) {
			if (is_same_union(union_find, a, b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		else if (order == 0) {
			union_set(union_find, a, b);
		}
	}
}

