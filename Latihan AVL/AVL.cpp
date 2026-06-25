#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure of AVL Tree (variable depends on the case)

struct Tree {
	
	int value;
	Tree *right, *left;
	int height;
	
} *root = NULL;

// Create New Node Function

struct Tree* createNewNode (int value){
	
	struct Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->value = value;
	node->height = NULL;
	node->left = node->right = NULL;
	
	return node;
	
}

// 3 Function helper in AVL Tree

// Function to give the height of a node

int height (Tree* curr){
	
	if(!curr) return 0;
	
	return curr->height;	
}

// Function to check maximum

int max (int a, int b){
	
	return(a > b)? a:b;
	
}

// Function to check the balance of the Tree

int getBalance (Tree* node){
	
	if(!node) return 0;
	
	return height(node->left) - height(node->right);
	
}

// Rotation Function (2 rotate type: Left Rotate and Right Rotate)

// Left Rotate Function

struct Tree* leftRotate(Tree* curr){
	
	Tree *currChild = curr->right;
	Tree *currChildChild = currChild->left;
	
	currChild->left = curr;
	curr->right = currChildChild;
	
	curr->height = max(height(curr->left), height(curr->right)) +1;
	currChild->height = max(height(currChild->left), height(currChild->right)) + 1;
	
	return currChild;
	
}

// Right Rotate Function

struct Tree* rightRotate(Tree* curr){
	
	Tree *currChild = curr->left;
	Tree *currChildChild = currChild->right;
	
	currChild->right = curr;
	curr->left = currChildChild;
	
	curr->height = max(height(curr->left), height(curr->right)) + 1;
	currChild->height = max(height(currChild->left), height(currChild->right)) +1;
	
	return currChild;
	
}

// Core Function in all of data structures

// Push Function in AVL Tree

struct Tree* push (Tree* curr, int value) {

	if(!curr){
		curr = createNewNode(value);
	}
	else if(value != curr->value){
		if(value < curr->value) curr->left = push(curr->left, value);
		else curr->right = push(curr->right, value);
	}
	
	curr->height = max(height(curr->left), height(curr->right)) + 1;
	
	int balance = getBalance(curr);
	
	if(balance > 1 && value < curr->left->value){
		return rightRotate(curr);
	}
	
	if(balance < -1 && value > curr->right->value){
		return leftRotate(curr);
	}
	
	if(balance > 1 && value > curr->left->value){
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	
	if(balance < -1 && value < curr->right->value){
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	
	return curr;


}

struct Tree* findMax (Tree* curr){
	
	while(curr->right != NULL) curr = curr->right;
	return curr;
	
}

struct Tree* findMin (Tree* curr){
	
	while (curr->left != NULL) curr = curr->left;
	return curr;
	
}

// Pop Function

struct Tree* pop (Tree *curr, int value){
	
	if(curr==NULL){
		return NULL;
	}else if(value < curr->value){
		curr->left = pop(curr->left, value);
	}else if(value > curr->value){
		curr->right = pop(curr->right, value);
	}else{
		if(curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		
		else if(curr->left == NULL || curr->right == NULL ){
			Tree *temp;
			
			if(curr->left){
				temp = curr->left;
			}else{
				temp = curr->right;
			}
			
			free(curr);
			return temp;
		}
		
		else if(curr->left && curr->right){
			Tree *temp = findMax(curr->left);
			curr->value = temp->value;
			curr->left = pop(curr->left, temp->value);
		}
	}
	
	curr->height = max(height(curr->left), height(curr->right)) + 1;
	int balance = getBalance(curr);
	
	if(balance > 1 && getBalance(curr->left) >= 0)
		return rightRotate(curr);
		
	if(balance < -1 && getBalance(curr->right) < 0)
		return leftRotate(curr);
		
	if(balance > 1 && getBalance(curr->left) < 0){
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	
	if(balance < -1 && getBalance(curr->right) >= 0){
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	
	return curr;
	
}


// Search Function


Tree* search(Tree *curr, int value){
    if(curr == NULL) return NULL;

    if(value < curr->value)
        return search(curr->left, value);

    if(value > curr->value)
        return search(curr->right, value);

    return curr;
}


// Pre Order Print (AVL Tree using this type of printing)

void preOrder (Tree* curr){
	
	if (!curr) return;
	
	printf ("%d ", curr->value);
	if (curr->left != NULL) preOrder (curr->left);
	
	if (curr->right != NULL) preOrder (curr->right);
	
}


int main(){

    root = push(root, 50);
    root = push(root, 30);
    root = push(root, 70);
    root = push(root, 20);
    root = push(root, 40);
    root = push(root, 80);
    root = push(root, 100);
    root = push(root, 25);
    root = push(root, 10);
    root = push(root, 12);
    root = push(root, 15);

    printf("Tree: ");
    preOrder(root);
    printf("\n");

    if(search(root, 40))
        printf("40 found\n");
    else
        printf("40 not found\n");

    root = pop(root, 30);

    printf("After delete 30: ");
    preOrder(root);
    printf("\n");

    return 0;
}

