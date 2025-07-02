//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//// ¦�� ��(ODD) = 1, Ȧ�� ��(EVEN)= 2
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int T;
//    cin >> T;
//
//    for (int i = 0; i < T; i++) {
//        long long int N;
//        int M;
//        cin >> N >> M;
//
//        // choose�� ��ȭ�� �� ����
//        long long int num;
//        vector<int> choose;
//        for (int j = 0; j < M - 1; j++) {
//            cin >> num;
//            choose.push_back(num);
//        }
//
//        // Ȧ�� �� = ((N + 1)/2)^2
//        long long int odd_cnt = (N + 1) / 2;
//        long long int odd_sum = odd_cnt * odd_cnt;
//
//        // ¦�� �� = (N/2)*(N/2 + 1)
//        long long int even_cnt = N / 2;
//        long long int even_sum = even_cnt * (even_cnt + 1);
//
//
//        unordered_map<int, int> result;  // ������ ���� ���� �����
//
//        long long int res = odd_sum - even_sum; // �ƹ��͵� ���� �ʾ��� �� 
//
//        cout << res << " ";
//
//
//
//        for (int k = 0; k < choose.size(); k++) {
//            int choose_num = choose[k];
//            int current_state = result[choose_num]; // �� ���� �湮 x => 0, 1 => 2, 2 => 1
//
//            if (current_state == 0) {
//                if (choose_num % 2 == 0) {
//                    result[choose_num] = 1; // odd;
//                    res += (choose_num * 2);
//                }
//                else if (choose_num % 2 == 1) {
//                    result[choose_num] = 2; // even
//                    res -= (choose_num * 2);
//                }
//            }
//
//            else if (current_state == 1) {
//                result[choose_num] = 2;
//                res -= (choose_num * 2);
//            }
//
//            else if (current_state == 2) {
//                result[choose_num] = 1;
//                res += (choose_num * 2);
//            }
//
//            cout << res << " ";
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}
