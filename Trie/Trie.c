#include<stdio.h>
#include<stdlib.h>

struct Node {
    int stop;
    int count_next;
    struct Node *next[26];
};

void initNode(struct Node *node) {
    node->stop = 0;
    node->count_next = 0;
    int i;
    for (i = 0; i < 26; i++) node->next[i] = NULL;
}

struct Node* insert(struct Node *node, char S[], int idx) {
    if (node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));
        initNode(node);
    }
    if (S[idx] == NULL) {
        node->stop = 1;
        return node;
    }
    struct Node *temp = node->next[S[idx] - 'a'];
    node->next[S[idx] - 'a'] = insert(node->next[S[idx] - 'a'], S, idx + 1);
    if (temp != node->next[S[idx] - 'a']) {
        node->count_next++;
    }
    return node;
}

int isEmpty(struct Node *node) {
    if (node->stop == 1) return 0;
    return node->count_next == 0;
}

struct Node* erase(struct Node *node, char S[], int idx) {
    if (node == NULL) {
        return NULL;
    }
    if (S[idx] == NULL) {
        node->stop = 0;
        return node;
    }
    struct Node *temp = node->next[S[idx] - 'a'];
    node->next[S[idx] - 'a'] = erase(node->next[S[idx] - 'a'], S, idx + 1);
    if (temp != node->next[S[idx] - 'a']) {
        node->count_next--;
    }
    if (isEmpty(node)) {
        free(node);
        return NULL;
    }
    return node;
}

int search(struct Node *node, char S[], int idx) {
    if (node == NULL) {
        return 0;
    }
    if (S[idx] == NULL) {
        return node->stop;
    }
    return search(node->next[S[idx] - 'a'], S, idx + 1);
}

void print(struct Node *node, char S[], int idx) {
    if (node == NULL) return;
    if (node->stop) {
        printf("%s\n", S);
    }
    int i;
    for (i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        S[idx] = i + 'a';
        print(node->next[i], S, idx + 1);
        S[idx] = NULL;
    }
}

int main() {
	struct Node *root = NULL;
    
    root = insert(root, "binus", 0);
    root = insert(root, "bina", 0);
    root = insert(root, "bi", 0);
    root = insert(root, "binary", 0);
    root = insert(root, "nusantara", 0);
    
    // printf("%d\n", search(root, "binary", 0));
    // printf("%d\n", search(root, "bini", 0));
    // printf("%d\n", search(root, "bin", 0));
    
    // root = erase(root, "binary", 0);
    
    // printf("%d\n", search(root, "binary", 0));
    // printf("%d\n", search(root, "bina", 0));
    
    char S[10] = {0};
    print(root, S, 0);
}

