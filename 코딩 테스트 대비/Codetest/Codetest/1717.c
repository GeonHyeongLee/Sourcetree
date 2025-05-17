#include <stdio.h>

#define MAX 1000001

int n, m;
int parent[MAX];
int rank[MAX]; 

void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int find_parent(int x) {
	if (x != parent[x]) {
		parent[x] = find_parent(parent[x]);
	}
	return parent[x];
}

void set_union(int a, int b) {
	int roota = find_parent(a);
	int rootb = find_parent(b);

	if (roota != rootb) {
		if (rank[roota] > rank[rootb]) {
			parent[rootb] = roota;
		}
		else if (rank[rootb] > rank[roota]) {
			parent[roota] = rootb;
		}
		else {
			parent[rootb] = roota;
			rank[roota]++;
		}
	}
}

int judge_same(int a, int b) {
	return find_parent(a) == find_parent(b);
}

int main(void) {
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++) {
		int x, a, b;
		scanf("%d %d %d", &x, &a, &b);

		if (x == 0) {
			set_union(a, b);
		}
		else {
			if (judge_same(a,b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
}