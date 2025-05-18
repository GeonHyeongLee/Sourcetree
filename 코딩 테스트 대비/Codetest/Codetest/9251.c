//#include <stdio.h>
//#include <string.h>
//
//#define MAX 1001
//
//#define max(a,b) ((a) > (b) ? (a) : (b))
//
//char first_arr[MAX];
//char second_arr[MAX];
//
//int dp[MAX][MAX] = { 0 };
//
//int main() {
//	scanf("%s", first_arr);
//	scanf("%s", second_arr);
//
//	int len_first = strlen(first_arr);
//	int len_second = strlen(second_arr);
//
//	for (int i = 1; i <= len_first; i++) {
//		for (int j = 1; j <= len_second; j++) {
//			if (first_arr[i-1] == second_arr[j-1]) {
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//	}
//
//	printf("%d", dp[len_first][len_second]);
//}