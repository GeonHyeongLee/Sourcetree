#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N; //석호춘 살고 있는 사람 수
int M; // 기억하는 정보의 개수

int main(void) {

	cin >> N;

	map<string, int> name_map;
	vector<string> names(N);

	for (int i = 0; i < N; i++) {
		cin >> names[i];
		name_map[names[i]] = i;
	}

	cin >> M;
	
	vector<vector<int>> graphs(N);
	vector<int> in_degree(N, 0);

	for (int i = 0; i < M; i++) {
		string x, y; // y가 조상, x가 자손 조상에서 뻗어나가야 함
		cin >> x >> y;
		int idx_x = name_map[x];
		int idx_y = name_map[y];

		graphs[idx_y].push_back(idx_x);
		in_degree[idx_x] += 1;
	}

	queue<int> q;

	// 진입 차수가 0이라고 한다면 무조건 시조일 것이다. 시조 따로 저장할 것
	vector<string> roots;

	for (int i = 0; i < N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			roots.push_back(names[i]);
		}
	}

	// 조상 숫자
	cout << roots.size() << "\n";
	
	// 조상 출력
	sort(roots.begin(), roots.end());
	for (string root : roots) {
		cout << root << " ";
	}
	cout << "\n";

	// 연결된 자식들 구해야 할 것
	vector<vector<int>> childrens(N);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < graphs[cur].size(); i++) {
			int nxt = graphs[cur][i];
			in_degree[nxt] -= 1;

			// 여기 들어가면 안된다
			//childrens[cur].push_back(nxt);

			if (in_degree[nxt] == 0) {
				// 진입 차수를 1 제거해서 in_degree[nxt] == 0이 되었다면
				// 그때 그 nxt가 cur의 직계 자식이었다는 뜻이니까 이때 추가해야 함
				childrens[cur].push_back(nxt);
				q.push(nxt);
			}
		}
	}


	// 그럼 childrens에는 각자의 직계 자식의 index 번호가 적혀져 있을 것이다.
	
	// 일단 이름 순에 따라 정렬해야 되는데 names는 이름과 index가 중요하니까
	// 이걸 그냥 sort 시켜버리면 복잡해질 것이다
	// 그러므로 vector<pair<string,int>> name_match라는 vector를 하나 만들어서 여기에다
	// names[i], i를 push_back 하자
	vector<pair<string, int>> name_match;

	for (int i = 0; i < N; i++) {
		name_match.push_back({ names[i], i });
	}

	sort(name_match.begin(), name_match.end());
	
	
	for (int i = 0; i < N; i++) {
		auto cur = name_match[i];
		string name = name_match[i].first;
		int name_idx = name_match[i].second;

		// 이름 먼저 출력하고
		cout << name << " "; 
		// 이름에 따른 자녀 숫자 출력하고
		cout << childrens[name_idx].size() << " ";

		// 자녀 이름들 출력하고
		vector<string> child_names;

		for (int j = 0; j < childrens[name_idx].size(); j++) {
			int child_idx = childrens[name_idx][j];
			child_names.push_back(names[child_idx]);
		}

		sort(child_names.begin(), child_names.end());

		for (auto name : child_names) {
			cout << name << " ";
		}
		cout << "\n";
	}


}