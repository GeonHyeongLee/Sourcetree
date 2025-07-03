#include <iostream>
#include <vector>
using namespace std;


// �̷��� Ǯ���� ���� 1 , 100 , 2, 3, 4 ó��
// �� �� ������ �ö� ���� ���� �κ� ������ 3���� �߸� ��Ҵ�.
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
	
	// dp[i]�� i��° ���Ҹ� ���������� �ϴ� LIS�� ���̶�� ����
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << dp[N - 1] << endl;
}