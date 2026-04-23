#include <stdio.h>
#define MAX 10000

int queue[MAX];
int front = 0;
int rear = -1;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        queue[++rear] = val;
    }
    
    int first = 1;
    for (int i = front; i <= rear; i++) {
        if (!first) printf(" ");
        printf("%d", queue[i]);
        first = 0;
    }
    printf("\n");
    return 0;
}
