#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int val;
            scanf("%d", &val);
            if (top < MAX - 1) {
                stack[++top] = val;
            }
        } else if (op == 2) {
            if (top >= 0) {
                printf("%d\n", stack[top--]);
            } else {
                printf("Stack Underflow\n");
            }
        } else if (op == 3) {
            if (top >= 0) {
                int first = 1;
                for (int j = top; j >= 0; j--) {
                    if (!first) printf(" ");
                    printf("%d", stack[j]);
                    first = 0;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
