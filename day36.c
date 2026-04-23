#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        
        if (front == NULL) {
            front = newNode;
            rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }
    
    int m;
    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            if (front != NULL) {
                if (front == rear) {
                    free(front);
                    front = NULL;
                    rear = NULL;
                } else {
                    struct Node* temp = front;
                    front = front->next;
                    rear->next = front;
                    free(temp);
                }
            }
        }
    }
    
    if (front != NULL) {
        struct Node* curr = front;
        int first = 1;
        do {
            if (!first) printf(" ");
            printf("%d", curr->data);
            first = 0;
            curr = curr->next;
        } while (curr != front);
        printf("\n");
    }
    
    return 0;
}
