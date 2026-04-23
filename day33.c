#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char str[2000];
    if (scanf("%1999s", str) != 1) return 0;
    
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("%c", c);
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            if (top >= 0 && stack[top] == '(') top--;
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }
    
    while (top >= 0) {
        printf("%c", stack[top--]);
    }
    printf("\n");
    return 0;
}
