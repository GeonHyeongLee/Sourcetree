#include <iostream>
#include <vector>
using namespace std;


// 이렇게 풀었을 때는 1 , 100 , 2, 3, 4 처럼
// 한 번 꺾었다 올라갈 때의 최장 부분 수열을 3으로 잘못 잡았다.
int main(void) {
	int N;
	cin >> N;    

	vector<int> arr(N+1,0);

	// 10, 20, 10, 30, 20, 50
	// 30, 10, 20
	// 1, 100, 20 , 30, 40
	                                  
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> dp(N + 1, 1);
	
	// dp[i]가 i번째 원소를 마지막으로 하는 LIS의 길이라고 생각
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << dp[N - 1] << endl;
}