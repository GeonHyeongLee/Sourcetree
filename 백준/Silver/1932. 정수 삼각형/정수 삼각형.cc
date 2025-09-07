#include <iostream>
#include <vector>

using namespace std;

vector<int> triangle[501];
int n;

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < i + 1; j++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		for (int j = 0; j < v.size(); j++) {
			triangle[i].push_back(v[j]);
		}
	}
	// n = 5 => i = 0 , 1 , 2 , 3 => j = (0) ,(0, 1), (0,1,2) => 
	// result = max(result + triangle[1][0], result + triangle[1][1])
	// result = max(result + triangle[2][0], 

	vector<vector<int>> dist(501, vector<int>(501, 0));
	dist[0][0] = triangle[0][0];

	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0) {
				dist[i][j] = dist[i - 1][0] + triangle[i][j];
			}
			else if (j == i) {
				dist[i][j] = dist[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dist[i][j] = max(dist[i - 1][j - 1] + triangle[i][j], dist[i - 1][j] + triangle[i][j]);
			}
		}
	}
	
	int max_result = 0;

	for (int i = 0; i < dist[n - 1].size(); i++) {
		max_result = max(max_result, dist[n - 1][i]);
	}

	cout << max_result;
}