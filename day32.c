#include <stdio.h>
#define MAX 10000

int stack[MAX];
int top = -1;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }
    
    int m;
    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            if (top >= 0) top--;
        }
    }
    
    int first = 1;
    for (int i = top; i >= 0; i--) {
        if (!first) printf(" ");
        printf("%d", stack[i]);
        first = 0;
    }
    printf("\n");
    return 0;
}
