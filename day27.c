#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        while(scanf("%d", &val) != 1) if(getchar() == EOF) return 0;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head1 == NULL) { head1 = newNode; tail1 = newNode; }
        else { tail1->next = newNode; tail1 = newNode; }
    }
    
    int m;
    if (scanf("%d", &m) != 1) return 0;
    
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        while(scanf("%d", &val) != 1) if(getchar() == EOF) return 0;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head2 == NULL) { head2 = newNode; tail2 = newNode; }
        else { tail2->next = newNode; tail2 = newNode; }
    }
    
    struct Node* p1 = head1;
    struct Node* p2 = head2;
    
    int diff = n > m ? n - m : m - n;
    if (n > m) {
        for (int i = 0; i < diff; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++) p2 = p2->next;
    }
    
    int intersectVal = -1;
    int found = 0;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            struct Node* t1 = p1;
            struct Node* t2 = p2;
            int valid = 1;
            while(t1 != NULL && t2 != NULL) {
                if (t1->data != t2->data) { valid = 0; break; }
                t1 = t1->next; t2 = t2->next;
            }
            if (valid) {
                found = 1; intersectVal = p1->data; break;
            }
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if (found) printf("%d\n", intersectVal);
    else printf("No Intersection\n");
    
    return 0;
}
