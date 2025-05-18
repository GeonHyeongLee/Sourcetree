//#include <stdio.h>
//
//#define MAX 501
//
//int m;
//int n;
//
//int map[MAX][MAX];
//
//int dx[4] = {0,0,-1,1};
//int dy[4] = {-1,1,0,0};
//
//int dp[MAX][MAX];
//
//int dfs(int x, int y) {
//
//	if (x == m-1 && y == n-1) {
//		return 1;
//	}
//
//	if (dp[x][y] != -1) {
//		return dp[x][y];
//	}
//
//	int count = 0;
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
//			if (map[nx][ny] < map[x][y]) {
//				count += dfs(nx, ny);
//			}
//		}
//	}
//	
//	dp[x][y] = count;
//
//	return count;
//}
//
//int main() {
//
//	scanf("%d %d", &m, &n);
//
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &map[i][j]);
//		}
//	}
//
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			dp[i][j] = -1;
//		}
//	}
//
//	int result = dfs(0, 0);
//	printf("%d", result);
//
//	return 0;
//}