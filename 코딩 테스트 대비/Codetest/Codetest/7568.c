#include <stdio.h>

#define MAX 51

int n;

int arr[MAX][2];

int rank[MAX];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (int i = 0; i < n; i++) {
		rank[i] = 1;

		for (int j = 0; j < n; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				rank[i] += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", rank[i]);
	}
}