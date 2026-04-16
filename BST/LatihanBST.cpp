#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node {
	
	int key;
	Node *left, *right;
	
} *root;


void search (struct Node* curr, int find){
	
	if(curr == NULL){
		printf("not found\n");
		return;
	}
	
	if(curr->key == find){
		printf("found\n");
		return;
	}
	
	if(find>curr->key){
		return search(curr->right, find);
	}else{
		return search(curr->left, find);
	}
}


void insert (struct Node* curr, int val){
	
	struct Node *newNode = (Node*) malloc (sizeof(Node));
	
	newNode->key = val;
	newNode->left = newNode->right = NULL;
	
	if (root == NULL){
		root = newNode;
	}
	
	else if (val != curr->key){
		if (val < curr->key && curr->left == NULL){
			curr->left = newNode;
		}
		else if (val > curr->key && curr->right == NULL){
			curr->right = newNode;
		}
		else if (val < curr->key && curr->left != NULL){
			insert (curr->left, val);
		}
		else if (val > curr->key && curr->left != NULL){
			insert (curr->right, val);
		}
	}
	
}


void inOrderTraversal (struct Node* curr){
	if(curr==NULL) return;
	
	inOrderTraversal(curr->left);
	printf("%d ", curr->key);
	inOrderTraversal(curr->right);
	
}


void preOrderTraversal (struct Node* curr){
	if(curr==NULL) return;
	
	printf("%d ", curr->key);
	preOrderTraversal(curr->left);
	preOrderTraversal(curr->right);
}


void postOrderTraversal (struct Node* curr){
	if(curr==NULL) return;
	
	postOrderTraversal(curr->left);
	postOrderTraversal(curr->right);
	printf("%d ", curr->key);
}



// Delete using predecessor

void executeDeleteNode(struct Node* parent, struct Node* curr) {
	if(parent == curr && curr->left == NULL && curr->right == NULL){
		free(curr);
		root = NULL;
		return;
	}
	
	else if(parent == curr && (curr->left == NULL || curr->right == NULL)){
		struct Node* child = (curr->left == NULL)? curr->right : curr->left;
		root=child;
		free(curr);
		curr=NULL;
		return;
	}
	
	else if(curr->left == NULL && curr->right == NULL){
		if(parent->left == curr){
			parent->left = NULL;
		}
		else parent->right == NULL;
		
		free(curr);
		return;
	}
	
	else if(curr->left == NULL || curr->right == NULL ){
		struct Node* child = (curr->left == NULL)? curr->right : curr->left;
		
		if(parent->left == curr){
			parent->left = child;
		}else parent->right = child;
		
		free(curr);
		return;
	}
	
	else{
		struct Node* predecessorParent = curr;
		struct Node* predecessor = curr->left;
		
		while(predecessor->right != NULL){
			predecessorParent = predecessor;
			predecessor = predecessor->right;
		}
		
		curr->key = predecessor->key;
		
		if(predecessorParent->left == predecessor){
			predecessorParent->left = (predecessor->left == NULL) ? predecessor->right : predecessor->left;
		}
		else predecessorParent->right = (predecessor->left == NULL) ? predecessor->right : predecessor->left;
		
		free(predecessor);
		return;
	}

    
}


void deleteNode (struct Node* curr, int find){
	
	struct Node* parent = curr;
	
	while (curr && curr->key != find){
		if (find < curr->key){
			parent = curr;
			curr = curr->left;
		}
		else if  (find > curr->key){
			parent = curr;
			curr = curr->right;
		}
	}
	
	if (!curr){
		printf ("%d is not found");
	}
	
	else if (curr->key == find){
		executeDeleteNode (parent, curr);
	}
	
}


int minValue (struct Node* node){
	if(node == NULL) return NULL;
	
	if(node->left == NULL) return node->key;
	
	return minValue(node->left);

}


int maxValue (struct Node* node){
	if(node == NULL) return NULL;
	
	if(node->right == NULL) return node->key;
	
	return maxValue(node->right);
	
}


int count (struct Node* node){
	if(node == NULL) return NULL;
	
	return(1 + count(node->left) + count(node->right));
}


int height (struct Node* node){
	if(node == NULL) return NULL;
	
	int heightL = height(node->left);
	int heightR = height(node->right);
	
	return 1 + (heightL>heightR? heightL:heightR);
	
	
}


int main(){
	
	root = NULL;
	
	insert (root, 54);
	insert (root, 81);
	insert (root, 16);
	insert (root, 27);
	insert (root, 9);
	insert (root, 36);
	insert (root, 63);
	insert (root, 72);
	
	printf ("Total Node in BST: %d\n", count(root));
	
	printf ("Height of Binary Tree: %d\n", height(root));
	
	printf ("\nInorder: "); inOrderTraversal (root); puts ("");
	printf ("\nPreorder: "); preOrderTraversal (root); puts ("");
	printf ("\nPostorder: "); postOrderTraversal (root); puts ("");
	
	puts ("");
	
	deleteNode (root, 54);
	
	printf ("\nPreorder (after del 54): "); preOrderTraversal (root); puts ("");
	
	deleteNode (root, 9);
	
	printf ("\Postorder (after del 9): "); postOrderTraversal (root); puts ("");
	
	deleteNode (root, 81);
	
	printf ("\Inorder (after del 81): "); inOrderTraversal (root); puts ("");
	
	puts ("");
	
	printf ("Min Value: %d\n", minValue(root));
	printf ("Max Value: %d\n", maxValue(root));
	
	puts ("");
	
	search (root, 72);
	search (root, 8);
	
	return 0;
	
}

