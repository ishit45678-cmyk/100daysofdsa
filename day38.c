#include <stdio.h>
#include <string.h>

#define MAX 10000
int deque[MAX];
int front = -1;
int rear = -1;

int main() {
    char op[20];
    while (scanf("%s", op) == 1) {
        if (strcmp(op, "push_front") == 0) {
            int val;
            scanf("%d", &val);
            if (front == -1) {
                front = 0; rear = 0;
                deque[front] = val;
            } else {
                front = (front - 1 + MAX) % MAX;
                deque[front] = val;
            }
        } else if (strcmp(op, "push_back") == 0) {
            int val;
            scanf("%d", &val);
            if (front == -1) {
                front = 0; rear = 0;
                deque[rear] = val;
            } else {
                rear = (rear + 1) % MAX;
                deque[rear] = val;
            }
        } else if (strcmp(op, "pop_front") == 0) {
            if (front != -1) {
                if (front == rear) {
                    front = -1; rear = -1;
                } else {
                    front = (front + 1) % MAX;
                }
            }
        } else if (strcmp(op, "pop_back") == 0) {
            if (front != -1) {
                if (front == rear) {
                    front = -1; rear = -1;
                } else {
                    rear = (rear - 1 + MAX) % MAX;
                }
            }
        } else if (strcmp(op, "front") == 0) {
            if (front == -1) printf("-1\n");
            else printf("%d\n", deque[front]);
        } else if (strcmp(op, "back") == 0) {
            if (front == -1) printf("-1\n");
            else printf("%d\n", deque[rear]);
        } else if (strcmp(op, "size") == 0) {
            if (front == -1) printf("0\n");
            else if (rear >= front) printf("%d\n", rear - front + 1);
            else printf("%d\n", MAX - front + rear + 1);
        } else if (strcmp(op, "empty") == 0) {
            if (front == -1) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
