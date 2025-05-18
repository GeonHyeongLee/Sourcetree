//#include <stdio.h>
//
//#define MAX 1001
//
//int n, m, v;
//
//int graph[MAX][MAX];
//
//int visited_d[MAX] = { 0 };
//int visited_b[MAX] = { 0 };
//
//int dfs(int v) {
//	visited_d[v] = 1;
//	printf("%d ", v);
//
//	for (int i = 1; i <= n; i++) {
//		if (visited_d[i] == 0 && graph[v][i] == 1) {
//			dfs(i);
//		}
//	}
//}
//
//typedef struct _queue_t {
//	int data[MAX];
//	int front;
//	int rear;
//} queue;
//
//void initQueue(queue* q) {
//	q->front = 0;
//	q->rear = 0;
//}
//
//void enQueue(queue* q, int value) {
//	q->data[q->rear] = value;
//	q->rear++;
//}
//
//int deQueue(queue* q) {
//	int value = q->data[q->front];
//	q->front++;
//	return value;
//}
//
//int isEmpty(queue* q) {
//	return q->front == q->rear;
//}
//
//
//int bfs(int v) {
//	visited_b[v] = 1;
//	queue q;
//	initQueue(&q);
//	enQueue(&q, v);
//
//	while (!isEmpty(&q)) {
//		int node = deQueue(&q);
//		printf("%d ", node);
//		for (int i = 1; i <= n; i++) {
//			if (visited_b[i] == 0 && graph[node][i] == 1) {
//				enQueue(&q, i);
//				visited_b[i] = 1;
//			}
//		}
//	}
//}
//
//int main() {
//	scanf("%d %d %d", &n, &m, &v);
//
//	for (int i = 0; i < m; i++) {
//		int p, q;
//		scanf("%d %d", &p, &q);
//		graph[p][q] = 1;
//		graph[q][p] = 1;
//	}
//
//	dfs(v);
//
//	printf("\n");
//
//	bfs(v);
//
//	printf("\n");
//
//	return 0;
//}