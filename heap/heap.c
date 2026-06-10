#include <stdio.h>

int HEAP[100];
int size = 0;

void swap(int u, int v) {
    int temp = HEAP[u];
    HEAP[u] = HEAP[v];
    HEAP[v] = temp;
}

void push(int val) {
    size++;
    HEAP[size] = val;
    
    int cur = size;
    while (cur != 1 && HEAP[cur] < HEAP[cur / 2]) {
        swap(cur, cur / 2);
        cur /= 2;
    }
}

void pop() {
    HEAP[1] = HEAP[size];
    size--;
    
    int cur = 1;
    while (cur * 2 <= size) {
        int next = cur;
        if (HEAP[cur] > HEAP[cur * 2]) 
			next = cur * 2;
        if (cur * 2 + 1 <= size && HEAP[next] > HEAP[cur * 2 + 1]) {
            next = cur * 2 + 1;
        }
        if (next == cur) break;
        swap(cur, next);
        cur = next;
    }
}

int top() {
    return HEAP[1];
}

int main() {
	int A[10] = {5, 7, 3, 2, 7, 6, 1, 9, 8, 10};
	int i;
	for (i = 0; i < 10; i++) {
	    push(A[i]);
	}
	for (i = 0; i < 10; i++) {
	    printf("%d ", top());
	    pop();
	}
	
}

