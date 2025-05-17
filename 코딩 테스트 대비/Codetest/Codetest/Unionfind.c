#include <stdio.h>

#define MAX 1001

int parent[MAX]; // 각 원소의 부모를 저장하는 배열
int rank[MAX]; // 각 원소의 랭크(트리의 높이)를 저장하는 배열


// 초기화 : 각 원소의 부모를 자기 자신으로 결정
void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

// Find : 주어진 원소의 루트(대표자)를 찾는 함수
int find(int x) {
	if (parent[x] != x) {
		// 경로 압축(Path Compression)
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

// Union : 두 원소를 같은 집합으로 합치는 함수
void union_sets(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	// 두 원소가 이미 같은 집합에 속하면 합치지 않음
	if (rootX != rootY) {
		// 유니온 by 랭크(Union by Rank)
		// 랭크가 작은 트리를 랭크가 큰 트리 밑에 합친다
		if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else {
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}
}

// 두 원소가 같은 집합에 속하는지 확인하는 함수
int same_set(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	init(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (same_set(a, b)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
			union_sets(a, b);
		}
	}

	return 0;
}