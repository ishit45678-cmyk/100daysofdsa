#include <stdio.h>
#include <string.h>

#define MAX 100000
int heap[MAX];
int size = 0;

void insert(int val) {
    heap[size] = val;
    int curr = size;
    size++;
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        int temp = heap[(curr - 1) / 2];
        heap[(curr - 1) / 2] = heap[curr];
        heap[curr] = temp;
        curr = (curr - 1) / 2;
    }
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(smallest);
    }
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) {
        size--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        char op[15];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            if (size > 0) printf("%d\n", heap[0]);
            else printf("-1\n");
        }
    }
    return 0;
}
