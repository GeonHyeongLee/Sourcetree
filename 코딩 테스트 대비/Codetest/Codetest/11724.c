#include <stdio.h>

#define MAX 1001

int n, m;
int graph[MAX];
int rank[MAX];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		graph[i] = i;
		rank[i] = 0;
	}
}

int find(int v) {
	if (v != graph[v]) {
		graph[v] = find(graph[v]);
	}
	return graph[v];
}

void set_union(int u, int v) {
	int rootu = find(u);
	int rootv = find(v);

	if (rootu != rootv) {
		if (rank[rootu] > rank[rootv]) {
			graph[rootv] = rootu;
		}
		else if (rank[rootv] > rank[rootu]) {
			graph[rootu] = rootv;
		}
		else {
			graph[rootv] = rootu;
			rank[rootv]++;
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		set_union(u, v);
	}



	int count = 0;

	for (int i = 1; i <= n; i++) {
		if (graph[i] == i) {
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}