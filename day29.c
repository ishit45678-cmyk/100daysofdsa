#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int val;
        while(scanf("%d", &val) != 1) if(getchar() == EOF) return 0;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int k;
    while(scanf("%d", &k) != 1) if(getchar() == EOF) return 0;
    
    k = k % n;
    if (k < 0) k += n;
    
    if (k > 0) {
        tail->next = head; 
        int steps = n - k;
        struct Node* newTail = tail;
        while (steps--) {
            newTail = newTail->next;
        }
        head = newTail->next;
        newTail->next = NULL;
    }
    
    struct Node* curr = head;
    int first = 1;
    while (curr != NULL) {
        if (!first) printf(" ");
        printf("%d", curr->data);
        first = 0;
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
