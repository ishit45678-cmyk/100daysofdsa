#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int c, e;
        while(scanf("%d", &c) != 1) if(getchar() == EOF) return 0;
        while(scanf("%d", &e) != 1) if(getchar() == EOF) return 0;
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;
        if (head == NULL) { head = newNode; tail = newNode; }
        else { tail->next = newNode; tail = newNode; }
    }
    
    struct Node* curr = head;
    int first = 1;
    while (curr != NULL) {
        if (curr->coeff != 0) {
            if (!first) {
                if (curr->coeff > 0) printf(" + ");
                else printf(" - ");
            } else {
                if (curr->coeff < 0) printf("-");
            }
            int abs_c = curr->coeff < 0 ? -curr->coeff : curr->coeff;
            
            // Standard formatting omit 1 prefix unless exponent is 0
            if (abs_c != 1 || curr->exp == 0) {
                printf("%d", abs_c);
            }
            
            if (curr->exp > 1) {
                printf("x^%d", curr->exp);
            } else if (curr->exp == 1) {
                printf("x");
            }
            first = 0;
        }
        curr = curr->next;
    }
    if (first) {
        printf("0");
    }
    printf("\n");
    return 0;
}
