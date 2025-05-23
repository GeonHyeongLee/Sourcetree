#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> q;
    char order[10];  // 명령어를 저장할 배열

    for (int i = 0; i < n; i++) {
        scanf("%s", order);

        if (strcmp(order, "push") == 0) {
            int num;
            scanf("%d", &num);
            q.push(num);
        }
        else if (strcmp(order, "pop") == 0) {
            if (q.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (strcmp(order, "size") == 0) {
            printf("%zu\n", q.size());
        }
        else if (strcmp(order, "empty") == 0) {
            printf("%d\n", q.empty() ? 1 : 0);
        }
        else if (strcmp(order, "front") == 0) {
            if (q.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", q.front());
            }
        }
        else if (strcmp(order, "back") == 0) {
            if (q.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", q.back());
            }
        }
    }

    return 0;
}