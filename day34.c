#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) return 0;
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char token[100];
    while (scanf("%s", token) == 1) {
        if (strcmp(token, "+") == 0) {
            int b = pop();
            int a = pop();
            push(a + b);
        } else if (strcmp(token, "-") == 0) {
            int b = pop();
            int a = pop();
            push(a - b);
        } else if (strcmp(token, "*") == 0) {
            int b = pop();
            int a = pop();
            push(a * b);
        } else if (strcmp(token, "/") == 0) {
            int b = pop();
            int a = pop();
            push(a / b);
        } else {
            push(atoi(token));
        }
    }
    printf("%d\n", pop());
    return 0;
}
