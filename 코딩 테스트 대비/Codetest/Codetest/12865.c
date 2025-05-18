//#include <stdio.h>
//
//#define max(a,b) ((a) > (b) ? (a) : (b))
//#define MAX_W 100001
//#define MAX_V 1001
//int n, k;
//int W[MAX_W];
//int V[MAX_W];
//
//int dp[MAX_W];
//
//int main() {
//	scanf("%d %d", &n, &k);
//
//	for (int i = 1; i <= n; i++) {
//		int w, v;
//		scanf("%d %d", &w, &v);
//		W[i] = w;
//		V[i] = v;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int w = k; w >= W[i]; w--) {
//			dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
//		}
//	}
//
//	printf("%d", dp[k]);
//}